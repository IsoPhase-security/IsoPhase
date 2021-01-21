#include "common.h"
using namespace cv;

//useful:
// sizeof(int *) is 8 bytes!
// sizeof(unsigned long) is 8 bytes!

char * ptr; // for futex, commands, m_handle and params for data copy
char * ptr_params; // for parameter sharing
char * ptr_real; // for actual data copy
char * ptr_vec; // for vector<Rect>

// Memory map:
// 0..3  | 4..5   | 6..13    | 14..15             | 16..23                     | 24..255  | ... 
// (repeat 2 more times for phase 2 and 3; last segment is unused)
// futex | cmd    | m_handle | size of next param | param used for data copy  |unused    | ... 
// ...
// 1024 | 1025..1026 | 1027..1155 |  ... (repeat 8 times) # IMPORTANT: returned value is put in the location of first argument
// orig | size       | data       | 
// ...
// 1024...1027 | 1028...1024*1024-1 (Mat only)
// size        | used for actual data copy
// 1024*1024      | 1024*1024+1..1024*1025-1 (vector<Rect> only)
// # of elements  | used for Rect data


static long sys_futex(void *addr1, int op, int val1, struct timespec *timeout, void *addr2, int val3)
{
        return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
}

int getshared(bool create){
        // create shared memory
        key_t key = 0xab;//ftok("shmfile", 66);
        int shmid;
	if (1)//create)
       		shmid = shmget(key, 1024*1027, IPC_CREAT|0666);
	else
       		shmid = shmget(key, 1024*1027, 0666);

	if (shmid < 0) {
                printf("[ERROR]: something went wrong when caling shmget()...\n");
                return 1; // finish execution
        }
        //printf("[DEBUG]: shmid is %d\n", shmid);
        ptr = (char *) shmat(shmid, (void *) 0, 0);
        if (ptr == (char *) -1){
                printf("[ERROR]: something went wrong when calling shmat()...\n");//, explain_shmat(shmid, NULL, 0));
                return 1;
        }
	printf("[DEBUG][getshared] ptr:%lx\n", ptr);
	ptr_params = &ptr[1024]; // this is the location of parameters
	ptr_real = &ptr[1024*2];
	ptr_vec = &ptr[1024*1026];
        return shmid;
}




void receivecommand(unsigned short * incoming, int phase){ 
	//printf("[DEBUG][receivecommand] ptr:%lx; (phase-1)*256+FUTEX_WORD_SIZE: %d\n", ptr, (phase-1)*256+FUTEX_WORD_SIZE);
        memcpy(incoming, &ptr[(phase-1)*256+FUTEX_WORD_SIZE], 2);
}

void sendcommand(unsigned short command, int phase){
	printf("[DEBUG][sendcommand] command:%d, phase:%d, ptr:%lx; (phase-1)*256+FUTEX_WORD_SIZE: %d\n", command, phase, ptr, (phase-1)*256+FUTEX_WORD_SIZE);
        //memset(&ptr[(phase-1)*256+FUTEX_WORD_SIZE], '\0', 2); 
	//printf("[DEBUG][sendcommand] &command[0]:%d, &command[1]:%d\n", &command[0], &command[1]);
	memcpy(&ptr[(phase-1)*256+FUTEX_WORD_SIZE], &command, 2);
}

//IMPORTANT: return values are stored in the location of the first argument
void sendparam(int index, char origin, int size, void * param){
		printf("[DEBUG][sendparam] index:%d, origin: %d, size:%d, param:%lx\n", index, origin, size, param);
		ptr_params[(index)*PARAMETER_SIZE] = origin;
		//ptr_params[(index)*PARAMETER_SIZE+META_INFO_SIZE+1] = type;
		memcpy(&ptr_params[(index)*PARAMETER_SIZE+1], &size, 2);
		memcpy(&ptr_params[(index)*PARAMETER_SIZE+3], param , size);
		//printf("[DEBUG][sendparam] ptr[(index)*PARAMETER_SIZE+3]:%lx\n", (void *) ptr[(index)*PARAMETER_SIZE+3]);

}

// this method copies Mat to the shared memory
void copy_mat2shared(Mat im){ //TODO: rename to copy_mat_obj
	//read param from unique location
	printf("[DEBUG][copy_mat2shared] im:%lx; im->rows:%u; im->cols:%u; im->data:%lx\n", im, im.rows, im.cols, im.data);
	int rows = im.rows;
	int cols = im.cols;
	int channels = im.channels();
	int nothing = 0;
	memcpy(ptr_real, &rows, 4);
	memcpy(ptr_real+4, &cols, 4);
	memcpy(ptr_real+8, &channels, 4);
	memcpy(ptr_real+12, &nothing, 4);
	memcpy(ptr_real+16, im.data, im.total()); // TODO: need to pass meta-information: rows, cols, channel, flags(?)
	
	printf("[DEBUG][copy_mat2shared] copy is complete!\n");	
}


/*
void copy_mat2shared(int pid){ //TODO: rename to copy_mat_obj
	//read param from unique location
	unsigned int size;
	void * ref;
	int nothing = NULL;
	memcpy(&size, &ptr[(pid-1)*256+META_INFO_SIZE], 2); //TODO we probably don't need size, assuming we know what kind of object that is
	memcpy(&ref, &ptr[(pid-1)*256+META_INFO_SIZE+2], 8);
	printf("[DEBUG][copy_mat2shared] ref:%lx; ptr_real:%lx!\n", ref, ptr_real);
	Mat * im = (Mat *) ref; 
	int rows, cols, channels;
	rows = im->rows;
	cols = im->cols;
	channels = im->channels();

	printf("[DEBUG][copy_mat2shared] im:%lx; im->rows:%u; im->cols:%u; im->data:%lx\n", im, im->rows, im->cols, im->data);
	memcpy(ptr_real, &rows, 4);
	memcpy(ptr_real+4, &cols, 4);
	memcpy(ptr_real+8, &channels, 4);
	memcpy(ptr_real+12, &nothing, 4);
	memcpy(ptr_real+16, im->data, im->rows*im->cols); // TODO: need to pass meta-information: rows, cols, channel, flags(?)
	
	printf("[DEBUG][copy_mat2shared] copy is complete!\n");	
}
*/

//pointer should be in first page
//this only applies to Recti (elemsize of 4B)
//TODO: there might be a bug here when rects.size > 0
void copy_rects2shared(vector<Rect> rects){
	unsigned int rects_size = rects.size();
	//printf("[DEBUG]rects.at(0).x: %u; &rects.at(0).x:%lx \n", rects.at(0).x, &rects.at(0).x);
	memcpy(ptr_vec, &rects_size, 4);
	for (int i=0; i < rects.size(); i++){
		Rect cur_rect = rects.at(i);
		memcpy(ptr_vec+4+(16*i), &cur_rect.x, 4); 
		memcpy(ptr_vec+8+(16*i), &cur_rect.y, 4);
		memcpy(ptr_vec+12+(16*i), &cur_rect.width, 4);
		memcpy(ptr_vec+16+(16*i), &cur_rect.height, 4);
	}

        printf("[DEBUG][copy_rect2shared] copy is complete!\n");
	
}

/*
void copy_rects2shared(int pid, vector<Rect> rects){
	unsigned int size;
        void * ref;
        memcpy(&size, &ptr[(pid-1)*256+14], 2); //TODO we probably don't need size, assuming we know what kind of object that is
        memcpy(&ref, &ptr[(pid-1)*256+14+2], 8);
        printf("[DEBUG][copy_rects2shared] ref:%lx; ptr_real:%lx!\n", ref, ptr_real);
        //vector<Rect> * rects = (vector<Rect>*) ref; 
	unsigned int rects_size = rects.size();
	//printf("[DEBUG]rects.at(0).x: %u; &rects.at(0).x:%lx \n", rects.at(0).x, &rects.at(0).x);
	memcpy(ptr_real, &rects_size, 4);
	for (int i=0; i < rects.size(); i++){
		Rect cur_rect = rects.at(i);
		memcpy(ptr_real+4+(16*i), &cur_rect.x, 4); printf("[DEBUG] ptr_real+4+(16*i):%lx (int:%u)\n", ptr_real+4+(16*i), *((unsigned int *)ptr_real+4+(16*i)) );
		memcpy(ptr_real+8+(16*i), &cur_rect.y, 4);
		memcpy(ptr_real+12+(16*i), &cur_rect.width, 4);
		memcpy(ptr_real+16+(16*i), &cur_rect.height, 4);
	}

        printf("[DEBUG][copy_rect2shared] copy is complete!\n");
	
}
*/


//this method copies a contiguous object to the shared memory
//TODO: actually never used!
void copy_obj2(int pid, map<unsigned long, size_t> sizes_map){ 
	//read param from unique location
        unsigned int size;
        void * ref;
        memcpy(&size, &ptr[(pid-1)*256+14], 2); //TODO we probably don't need size, assuming we know what kind of object that is
        memcpy(&ref, &ptr[(pid-1)*256+14+2], 8);
        printf("[DEBUG][copy_obj] ref:%lx; ptr_real:%lx!\n", ref, ptr_real);
	
	memcpy(ptr_real, &sizes_map[(unsigned long) ref], sizeof(unsigned int)); //copy size of continuous object
	memcpy(ptr_real + 4, ref, sizes_map[(unsigned long) ref]); //TODO: need to pass meta-information (obj-size -- should be unsigned int) as well


        printf("[DEBUG][copy_obj] copy is complete!\n");
}


void readparam(int pid, int index, void * param){ // param will be populated
	char origin = ptr_params[(index)*PARAMETER_SIZE];
	unsigned short size;
	memcpy(&size, &ptr_params[(index)*PARAMETER_SIZE+1], 2);
	printf("[DEBUG][readparam] origin:%d; size:%d; (index)*PARAMETER_SIZE+3:%d\n", origin, size,(index)*PARAMETER_SIZE+3);
	memcpy(param, &ptr_params[(index)*PARAMETER_SIZE+3] , size);
	//ptr_params[(index)*PARAMETER_SIZE+3 + size] = '\0';
}

void readparam_rects(int pid, int index, void * param){
	//request_copy(pid, index, 997); // rects should be there already

	unsigned int vec_size;
        memcpy(&vec_size, ptr_vec, 4);
	unsigned int x,y,width,height;
	vector<Rect> * rects = new vector<Rect>(); 
	for (int i = 0; i < vec_size; i++){
		memcpy(&x, ptr_vec+4+(16*i), 4); 
		memcpy(&y, ptr_vec+8+(16*i), 4);
		memcpy(&width, ptr_vec+12+(16*i), 4);
		memcpy(&height, ptr_vec+16+(16*i), 4);
		printf("[DEBUG][readparam_rects] x:%u, y:%u; width:%u; height%u\n", x,y, width, height);
		rects->push_back(Rect(x,y,width,height));
	}
	//param is unfortunately a reference
	memcpy(param, &rects, 8);
	
}
/*
void readparam_rects(int pid, int index, void * param){
	request_copy(pid, index, 997);

	unsigned int vec_size;
        memcpy(&vec_size, ptr_real, 4);
	unsigned int x,y,width,height;
	vector<Rect> * rects = new vector<Rect>(); 
	for (int i = 0; i < vec_size; i++){
		memcpy(&x, ptr_real+4+(16*i), 4); printf("ptr_real+4+(16*i):%lx (int:%u)\n", ptr_real+4+(16*i), *((unsigned int *)ptr_real+4+(16*i)) );

		memcpy(&y, ptr_real+8+(16*i), 4);
		memcpy(&width, ptr_real+12+(16*i), 4);
		memcpy(&height, ptr_real+16+(16*i), 4);
		printf("[DEBUG] x:%u, y:%u; width:%u; height%u\n", x,y, width, height);
		rects->push_back(Rect(x,y,width,height));
	}
	//param is unfortunately a reference
	memcpy(param, &rects, 8);
	
}
*/

// this is a modified version of readparam; it always request data copy
mat_info readparam_mat(int pid, int index, void * param){
	mat_info mat_inf;
	// request_copy(pid, index, 998); mat is already there
        // copy object
	unsigned int width, height, channels, extra;
	memcpy(&width, ptr_real, 4);
	memcpy(&height, ptr_real+4, 4);
	memcpy(&channels, ptr_real+8, 4);
	memcpy(&extra, ptr_real+12, 4); // TODO: consider using struct and only one memcpy
	printf("[DEBUG][readparam_mat] width:%u, height:%u; channels:%u; extra:%x\n", width, height, channels, extra);

        unsigned int size_obj = width*height*channels; // TODO: width, height, channel must be passed in shared memory
	void * obj = malloc(size_obj);
        printf("[DEBUG][readparam_mat] malloc(%u); malloc'ed obj: %lx\n", size_obj, obj);
        memcpy(obj, ptr_real+16, size_obj); 
	printf("[DEBUG][readparam_mat] memcpy completed\n");
        memcpy(param, &obj, 8); //param is actually a reference!
	mat_inf.width = width;
	mat_inf.height = height;
	mat_inf.channels = channels;
	mat_inf.extra = extra;
	return mat_inf;
}

void request_copy(int pid, int index, int command){
	char origin = ptr_params[(index)*PARAMETER_SIZE]; // get origin of parameter
        unsigned short size;
        memcpy(&size, &ptr_params[(index)*PARAMETER_SIZE+1], 2); // get size of parameter
        //printf("[DEBUG][readparam_mat] origin:%d; size:%d; (index)*PARAMETER_SIZE+META_INFO_SIZE+3:%d\n", origin, size,(index)*PARAMETER_SIZE+META_INFO_SIZE+3);
        sendcommand(command, origin); //request for object copy
        // we should send the reference as a param in a different place since we are already using the param page
        memcpy(&ptr[(origin-1)*256+META_INFO_SIZE], &size, 2);// TODO: copy directly from ptr_param; send size   
        memcpy(&ptr[(origin-1)*256+META_INFO_SIZE+2], &ptr_params[(index)*PARAMETER_SIZE+3], 8); //send ref
        wakeup(pid, origin); // wake up process that contains obj
        makesleep(pid, origin); // sleep on target process futex
}


void sendhandle(void * reference, int phase){
	//printf("[sendhandle] %u\n", (phase-1)*256+FUTEX_WORD_SIZE+COMMAND_SIZE);
	memset(&ptr[(phase-1)*256+FUTEX_WORD_SIZE+COMMAND_SIZE], '\0', 8); 
        memcpy(&ptr[(phase-1)*256+FUTEX_WORD_SIZE+COMMAND_SIZE], &reference, 8);
	
}

void * receivehandle (int phase){
	//printf("[receivehandle] %u\n ", (phase-1)*256+FUTEX_WORD_SIZE+COMMAND_SIZE);
	void * m_handle;
        memcpy(&m_handle, &ptr[(phase-1)*256+FUTEX_WORD_SIZE+COMMAND_SIZE], 8);
        return m_handle;

}

void wakeup(int pid, int phase){
        printf("[DEBUG][%d] Waking someone up!\n", pid);
        int futex_rc = sys_futex(&ptr[(phase-1)*256], FUTEX_WAKE, 1, NULL, NULL, 0); // NOTE: do not use FUTEX_WAKE_BITSET b/c it's probably less efficient than having multiple futexes according to the man page
        if (futex_rc == 0 || futex_rc == -1) {
		printf("[ERROR][%d] Something went wrong and I can't wake someone up... futex_rc:%d, errno:%d. Retrying...\n", pid, futex_rc, errno);
		sleep(1); //TODO: investigate why this is necessary when requesting Mat from phase1 by phase2
		futex_rc = sys_futex(&ptr[(phase-1)*256], FUTEX_WAKE, 1, NULL, NULL, 0);
		if (futex_rc == 0 || futex_rc == -1) {
		                printf("[ERROR][%d] Something went wrong and I can't wake someone up... futex_rc:%d, errno:%d. Retrying...\n", pid, futex_rc, errno);

		}
	}

}

void makesleep(int pid, int phase){
        // sleeps while waiting for a phase's completion
        printf("[DEBUG][%d] I am about to sleep...\n", pid);
        memset(&ptr[(phase-1)*256], '\0', FUTEX_WORD_SIZE);
        ptr[(phase-1)*256] = 'A';
        int futex_rc = sys_futex(&ptr[(phase-1)*256], FUTEX_WAIT, 'A', NULL, NULL, 0);
        if (futex_rc == -1) printf("[DEBUG][%d] Something went wrong and I can't sleep.... futex_rc:%d, errno:%d\n", pid, futex_rc, errno);
        printf("[DEBUG][%d] I just woke up!\n", pid);
}

