#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <opencv2/opencv.hpp>
#include <libexplain/shmat.h>
//using namespace cv;

uchar * ptr;

extern "C" void getsharedmemory(void){
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key, 1024*1024, IPC_CREAT|SHM_HUGETLB|0666);
	if (shmid < 0) {
		//printf("[ERROR]: something went wrong when caling shmget()...\n");
		return;
	}
	//printf("[DEBUG]: shmid is %d\n", shmid);		
	ptr = (uchar *) shmat(shmid, (void *) 0, 0);
	if (ptr == (uchar *) -1){
		//printf("[ERROR]: something went wrong when calling shmat()...\n");//, explain_shmat(shmid, NULL, 0));
		return;
	}
	//printf("[DEBUG]: ptr is %x\n", ptr);

}

extern "C" void sendtoshared(void * m, unsigned int rows, unsigned cols){
	if (m != NULL){
		int step = cols;
		//printf("[DEBUG]: step is %d\n", step);
		for(int i = 0; i < rows; i++){
			const uchar * cur = (const uchar *) m + i * step;
			memcpy((uchar *)(ptr + i * step), cur, step);
			//printf("[DEBUG]: cur is %lx; and (ptr + i * step) is %lx\n", cur ,(ptr + i * step));
		}
	}
	/*
       	else{
		printf("[ERROR]: m is NULL!\n");
	}*/	
}
