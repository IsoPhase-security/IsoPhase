#include "../common.h"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//TODO: create a map data structure that maps <address, size>


enum commandValues { NOOP, VIDEOCAPTURE_VOID, VIDEOCAPTURE_OPEN, VIDEOCAPTURE_ISOPENED, VIDEOCAPTURE_READ}; //this list will be very long (size of all the api calls)

using namespace cv;
Mat global_im;

int main(){
	unsigned short command;
       	void * m_handle;	
	getshared(0);
	VideoCapture * cap_main;
        while(1){
		makesleep(1, 1); // sleep on futex1
		printf("\n");
        	receivecommand(&command, 1); // read string command TODO: command should be integer 
                printf("[DEBUG][1] this is what I got: %d...\n", command);
		if (command == 400) break;
                switch(command){
			case NOOP:
				break;
                        case VIDEOCAPTURE_VOID:{
                                printf("[DEBUG][1] VideoCapture() requested!\n");
                                //VideoCapture * cap = new VideoCapture(0, 0, 0, 0); // this is on the heap
                                VideoCapture * cap = new VideoCapture(); // Stack doesn't really work here
				printf("[DEBUG][1] VideoCapture() created. Sending handler (it should be: %lx)!\n", cap);
                                sendhandle(cap, 1);
                                wakeup(1, 1); // wake-up original process
                                break;
                                		}
			case VIDEOCAPTURE_OPEN:{
				printf("[DEBUG][1] VideoCapture::open() requested! Setting m_handle...\n");
                               	m_handle = receivehandle(1);  
				printf("[DEBUG][1] m_handle(%lx) received!\n", m_handle);
				VideoCapture * cap = ((VideoCapture *) m_handle); //IMPORTANT: must only use pointers...
				int param0; // IMPORTANT: phase1 already knows that param0 is an integer...
				readparam(1, 0, &param0);
				printf("[DEBUG][1] Received param is %d\n", param0);
				printf("[DEBUG][1] VideoCapture::open(): ret value is %d!\n", cap->open(param0));
				printf("[DEBUG][1] VideoCapture::open(): isOpened() now returns %d\n", cap->isOpened());

                                wakeup(1, 1); // wake-up original process
                                break;
	
					       }
			case VIDEOCAPTURE_ISOPENED:{
				printf("[DEBUG][1] VideoCapture::isOpened() requested! Setting m_handle...\n");
                               	m_handle = receivehandle(1);  
				printf("[DEBUG][1] VideoCapture's m_handle is %lx...\n", m_handle);
				VideoCapture * cap =  ((VideoCapture *) m_handle);
				while(!cap->isOpened()){
					printf("not opened yet...\n");
					sleep(1);
				}
				bool ret = cap->isOpened();
				printf("[DEBUG][1] VideoCapture::isOpened() ret is %d\n", ret);
				sendparam(0, 1, 1, &ret); // make no mistake: we are sending the return value back!
				wakeup(1,1); // wake-up original process
				break;
								
						 }
			case VIDEOCAPTURE_READ:{
				printf("[DEBUG][1] VideoCapture::read() requested! Setting m_handle...\n");
                                m_handle = receivehandle(1);
                                VideoCapture * cap = ((VideoCapture *) m_handle);
                                //Mat im;
				bool ret;
				ret = cap->read(global_im); // no reference to im? That's why it gets deallocated?
				//TODO: must create return value for this method
				if (global_im.empty()) {
					sendhandle(&global_im, 1);
					sendparam(0, 1, 1, &ret);
					wakeup(1,1);
					break;
				}
				cvtColor(global_im, global_im, COLOR_BGR2GRAY, 1); 
                                printf("[DEBUG][1] Mat's handle is %lx; im.rows:%u; im.cols:%u; sizeof(global_im.data):%u; \n", &global_im, global_im.rows, global_im.cols, sizeof(global_im.data)); 
				sendhandle(&global_im, 1);
				copy_mat2shared(global_im);
				wakeup(1,1); // wake-up original process
                                break;

					       }

			case 5:{	
				printf("[DEBUG][1] VideoCapture::open(char *) requested! Setting m_handle...\n");
                                m_handle = receivehandle(1);
                                printf("[DEBUG][1] m_handle(%lx) received!\n", m_handle);
                                VideoCapture * cap = ((VideoCapture *) m_handle); //IMPORTANT: must only use pointers...
                                char param0[128] = {'\0'}; // IMPORTANT: phase1 already knows that param0 is an integer...
                                readparam(1, 0, param0);
                                printf("[DEBUG][1] Received param is %s\n", param0);
                                printf("[DEBUG][1] VideoCapture::open(): ret value is %d!\n", cap->open(param0));
                                printf("[DEBUG][1] VideoCapture::open(): isOpened() now returns %d\n", cap->isOpened());

                                wakeup(1, 1); // wake-up original process
                                break;


			       }
			case 998:{ // copy Mat
				printf("[DEBUG][1] copy_mat2shared(int) is deprecated!!!!\n");
                                //copy_mat2shared(1); // read reference from 0th page, and the copy to ptr_real
                                wakeup(1,1); // wake other process sleeping on futex
				break;

				 }
                        default:
                                printf("[DEBUG][1] I didn't understand the command...\n");
                                break;
                }
                //break;

        }
        printf("[DEBUG][1] end of execution!\n");

	return 0;
}
