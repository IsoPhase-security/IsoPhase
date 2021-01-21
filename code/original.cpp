#include "common.h"
#include <chrono>

using namespace std;
using namespace cv;

class Vector_Rect {
	public: 
		void * m_handle;
		int size_ret = -1; // used to store value of size; so we don't have to call the size() multiple time //TODO: apply same technique on other objects
		Vector_Rect(){};
		int size(){
			if (this->size_ret != -1){
				return this->size_ret;
			}
			else{
			//void * m_handle;
			printf("\n");
                        sendcommand(2,2);
                        wakeup(0,2);
                        makesleep(0,2);
                        //m_handle = receivehandle(2);
			readparam(0, 0, &this->size_ret);
                        printf("[DEBUG][0] size() completed with size:%d!\n", this->size_ret);

			}
		}
};

class Size__ {
	public:
		void * m_handle;
		Size__(){};
};

class Mat__ { // must have two underscore since Mat_ already exists...
	public:
		void * m_handle;
		Mat__(){ // this is never directly called by the user
			/*
			printf("\n");
			sendcommand(XXX,1);
                        wakeup(0,2);
                        makesleep(0,2);
		        m_handle = receivehandle(2);
                        printf("[DEBUG][0] Mat_() completed!\n");
			*/
		};

};

class CascadeClassifier_ { 
	public: 
		void * m_handle;
		void load( char * file){
			printf("\n");
			sendcommand(0, 2); // step 1: send command
			sendparam(0, 0, strlen(file), file); // step 2: send params (must iterate list of parameters) TODO: how to deal with functions that don't have any parameters in LLVM?
			wakeup(0, 2); // step 3: wake up phase process
			makesleep(0, 2); // step 4: sleep on futex
			m_handle = receivehandle(2); // step 5: receive handle TODO: some functions will not return anything
			printf("[DEBUG][0] m_handle for CascadeClassifier is %lx\n", m_handle);
		};

		void detectMultiScale(Mat__ im, Vector_Rect * faces, double scaleFactor, int minNeighbors, int flags, int size1, int size2){ // TODO: note that size1 and size2 should be combined in Size(size1, size2). Since Size() should be a phase2 process, we are shortcutting it
			printf("\n");
			sendhandle(m_handle, 2);
                        sendcommand(1, 2); // step 1: send command
                       	printf("[DEBUG][detectMultiScale] im.m_handle: %lx\n", im.m_handle); 
			sendparam(0, 1, 8, &(im.m_handle)); // step 2: send params (must iterate list of parameters) TODO: how to deal with functions that don't have any parameters in LLVM?
			sendparam(2, 0, 0, NULL); // the vector<Rect> will be created by phase 2. We just need to get its reference in the end
			sendparam(2, 0, sizeof(double), &scaleFactor);
			sendparam(3, 0, sizeof(int), &minNeighbors);
			sendparam(4, 0, sizeof(int), &flags);
			sendparam(5, 0, sizeof(int), &size1);
			sendparam(6, 0, sizeof(int), &size2);

                        wakeup(0, 2); // step 3: wake up phase process
                        makesleep(0, 2); // step 4: sleep on futex
                        faces->m_handle = receivehandle(2); // step 5: receive handle for faces // TODO: double check if this is ok...
			//TODO: we also need to update im's m_handle, since another process is using it //TODO: double check with Kwon
                        printf("[DEBUG][0] faces.m_handle:%lx &faces.m_handle:%lx\n", faces->m_handle, &faces->m_handle);


		};
};


class VideoCapture_ {
	public:
		void * m_handle;
		VideoCapture_(){
			printf("\n");
			sendcommand(1, 1);
		        wakeup(0, 1); 
		        makesleep(0, 1);
		        m_handle = receivehandle(1);
		        printf("[DEBUG][0] m_handle for VideoCapture is %lx\n", m_handle);
		};
		void open(int index){
			printf("\n");
			sendhandle(m_handle,1);
			sendcommand(2, 1);
			sendparam(0,0,sizeof(index),&index);
			wakeup(0,1);
			makesleep(0,1);
			printf("[DEBUG][0] VideoCapture_::load() completed!\n");
		};
		void open(char * file){
			printf("\n");
                        sendhandle(m_handle,1);
                        sendcommand(5, 1);
                     
                        sendparam(0,0,strlen(file),file);
                        wakeup(0,1);
                        makesleep(0,1);
                        printf("[DEBUG][0] VideoCapture_::load(char *) completed!\n");

		};
		bool isOpened(){
			printf("\n");
			sendhandle(m_handle,1);
			sendcommand(3,1);
			wakeup(0,1);
			makesleep(0,1);
			bool ret;
			readparam(0, 0, &ret); //read return value
			printf("[DEBUG][0] VideoCapture_::isOpened() completed (ret is %d)!\n", ret);

			return ret;
		};
		bool read(Mat__* im){ 
                        printf("\n");
                        sendhandle(m_handle,1); // send handle for videocapture
                        sendcommand(4,1); // send command for read
                        //sendparam//TODO: (OPTION 1) do we need to send im? in the end, its m_handle needs to be populated
			wakeup(0,1); 
                        makesleep(0,1);
			im->m_handle = receivehandle(1); //TODO: (OPTION 2) read the returned m_handle...
			bool ret;
			readparam(0, 0, &ret); //read return value
                        printf("[DEBUG][0] VideoCapture_::read(Mat__) completed! Mat__'s handle is %lx\n", im->m_handle);
			return ret;

                };

};


/*
VideoCapture_::VideoCapture_(){
	sendcommand(1, 1);
        wakeup(0, 1); 
        makesleep(0, 1);
        m_handler = receivehandle(1);
        printf("[DEBUG][0] m_handler for VideoCapture is %lx\n", m_handler);
}
*/

void rectangle_(Mat__ im, Vector_Rect *faces, int index, unsigned char b, unsigned char g, unsigned char r, int flag1){
	printf("\n");
        sendparam(0, 1, 8, &im.m_handle); // TODO: parameter origin in reality should be 2 instead of 1! The m_handle should be from the last phase process to use the object!
        printf("[DEBUG][0] faces.m_handle:%lx &faces.m_handle:%lx\n", faces->m_handle, &faces->m_handle);//faces.m_handle, &faces.m_handle);

	sendparam(1, 2, 8, &faces->m_handle);
	sendparam(2, 0, 4, &index);
	sendparam(3, 0, 1, &b);
	sendparam(4, 0, 1, &g);
	sendparam(5, 0, 1, &r);
	sendparam(6, 0, 4, &flag1);
	sendcommand(0, 3);
        wakeup(0,3);
        makesleep(0,3);
        printf("[DEBUG][0] rectangle_ completed!\n");
}	

void imshow__(char * name, Mat__ im){
	printf("\n");
        sendparam(0, 0, strlen(name), name);
	sendparam(1, 1, 8, &im.m_handle);
	sendcommand(1, 3);
	wakeup(0,3);
	makesleep(0,3);
	printf("[DEBUG][0] imshow__ completed\n");
}

int waitKey__(){
	printf("\n");
	int c;
	sendcommand(2, 3);
        wakeup(0,3);
        makesleep(0,3);
	readparam(0, 0, &c);
        printf("[DEBUG][0] waitKey__10 completed\n");
	return c;

}

void terminate_phase_processes(){
	printf("\nTermination requested!\n");
        sendcommand(400, 1);
        wakeup(0,1);
	sendcommand(400, 2);
	wakeup(0,2);
        sendcommand(400, 3);
	wakeup(0,3);
}


int main(){
	auto start = std::chrono::system_clock::now();
	int status;
	printf("[DEBUG] Start of application\n");
	getshared(1); // connect to shared memory
	//sleep(5);
	VideoCapture_ cap = VideoCapture_();
	CascadeClassifier_ cascade; //phase 2
	cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml"); //phase 2
	//cap.open(0); // phase1 //webcam
	cap.open("/home/marco/Documents/research/one_sec.mp4");
	//sleep(5); //wait for camera initialization
	Mat__ im;
	Vector_Rect faces; //vector<Rect> faces;
	//auto milestone = std::chrono::system_clock::now();
        //printf("[DEBUG] Elapsed time before loop:%f\n", (milestone-start).count());
	while (cap.isOpened()){ // phase1 
		auto loop_start = std::chrono::system_clock::now();
		if(!cap.read(&im)) // phase1 
			break;
		//printf("[DEBUG] im.m_handle: %lx\n", im.m_handle);	
		auto cap_read_end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_cap_read = cap_read_end-loop_start;
                printf("[DEBUG] time for cap.read(im):%f\n", (elapsed_cap_read).count());

		auto detect_start = std::chrono::system_clock::now();
		cascade.detectMultiScale(im, &faces, 1.1, 2, CASCADE_SCALE_IMAGE, 30, 30); //TODO: phase2: replaced Size(30, 30) with 30,30 ! EDIT: it's actually ok to replace constant values... (or not include them at all when sending params)
        	//printf("[DEBUG][0] faces.m_handle:%lx &faces.m_handle:%lx\n", faces.m_handle, &faces.m_handle);
		auto detect_end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_detect = detect_end-detect_start;
                printf("[DEBUG] time for cascade.detectMultiScale(im):%f\n", (elapsed_detect).count());



                auto rectangle_for_start = std::chrono::system_clock::now();
		for (size_t i = 0; i < faces.size(); i++){
			//rectangle(im, faces[i], Scalar(255,0,0), 1, 0, 0); // the wrapper function should be should have an additional param for index

			rectangle_(im, &faces, i, 255, 0, 0, 1); 
		}
		faces.size_ret = -1; //TODO: must make the size of faces become stale for next iteration
		auto rectangle_for_end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_rectangle = rectangle_for_end-rectangle_for_start;
                printf("[DEBUG] time for for loop with rectangle():%f\n", (elapsed_rectangle).count());
	


		auto imshow_start = std::chrono::system_clock::now();     
		imshow__("Window",im);
		auto imshow_end = std::chrono::system_clock::now();     
                std::chrono::duration<double> elapsed_imshow = imshow_end-imshow_start;
                printf("[DEBUG] time for imshow():%f\n", (elapsed_imshow).count());	




		char c = waitKey__();
		//printf("[DEBUG] c:%c\n", c);
		if (c == 27 || c == 'q'){
			break;
		}
		auto loop_end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_loop = loop_end-loop_start;
                printf("[DEBUG] time for loop (1 iteration):%f\n", elapsed_loop.count());
		printf("=====================================================================================================\n");	
	}
	auto start_term = std::chrono::system_clock::now();
	terminate_phase_processes();
	auto end = std::chrono::system_clock::now();
  	std::chrono::duration<double> elapsed_seconds = end-start;
  	std::chrono::duration<double> elapsed_term_seconds = end-start_term;
        printf("[DEBUG][0] Elapsed time for process termination:%f\n", elapsed_term_seconds.count());
	
	printf("[DEBUG][0] It's over! Elapsed:%f\n", elapsed_seconds.count());
	return 0;

}

