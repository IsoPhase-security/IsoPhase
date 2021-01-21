#include "../common.h"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <chrono>

//TODO: create a map data structure that maps <address, size>


enum phase3commands{ RECTANGLE , IMSHOW, WAITKEY__};
using namespace cv;

class VectorRect_{
	public:
		VectorRect_(){};
		vector<Rect> * recs = NULL; 
};

using namespace cv;
int main(){
	Mat im;
	unsigned short command; 
	void * m_handle;
	getshared(0);
        while(1){
		makesleep(3, 3); //phase3 sleep on futex3
		printf("\n");
        	receivecommand(&command, 3); // read string command TODO: command should be integer 
                printf("[DEBUG][3] this is what I got: %d...\n", command);
		if (command == 400) break;
                switch(command){
		
			//FIXME: right now we are copying the data from shared memory every time rectangle() is called. We should have a wrapper class that stores that information to avoid multiple reads 
                        case RECTANGLE:{
	                        printf("[DEBUG][3] rectangle() requested!\n");
                                void * im_m_handle;
				/*readparam(3, 0, &im_m_handle);

				*/
                                
				void * im_p;

				auto mat_start = std::chrono::system_clock::now();
				mat_info meta = readparam_mat(3, 0, &im_p);
			 	im = Mat(meta.width, meta.height, 0, im_p); // reconstruct Mat on this process
				auto mat_end = std::chrono::system_clock::now();
                		std::chrono::duration<double> elapsed_mat = mat_end-mat_start;
                		printf("[DEBUG] time for cap.read(im):%f\n", (elapsed_mat).count());
				//printf("[DEBUG][RECTANGLE] im.total():%u\n", im.total());
			
				VectorRect_ vectorRect;
				int index;
				readparam(3, 2, &index); // TODO: must take into account indexing with complex data structure... IDEA: create new method for indexing?
				
				readparam_rects(3, 1, &vectorRect.recs);
				


				
				
				int flag;
				unsigned char b, g, r;


				readparam(3, 3, &b);
				readparam(3, 4, &g);
				readparam(3, 5, &r);
				readparam(3, 6, &flag);
				//printf("[DEBUG][3] faces_p: %lx, faces: %lx\n", faces_p, faces); // sanity check
				printf("[DEBUG] vectorRect.recs: %lx\n", vectorRect.recs);	
				printf("[DEBUG][3] vectorRect.recs->size(): %u\n", vectorRect.recs->size()); // sanity check

				//FIXME: as stated above, we are drawing multiple times the same rectangles and reading them from shared memory everytime
				//if (vectorRect.recs->size() > 0){
				for (int ii = 0; ii < vectorRect.recs->size(); ii++){
					printf("[DEBUG][3] attempting to draw... b:%u; g:%u; r:%u; flag:%u; index:%d\n", b, g, r, flag, index);
					//printf("[DEBUG][3] vectorRect.recs->at(index).x:%u; vectorRect.recs->at(index).y:%u vectorRect.recs->at(index).width:%u; vectorRect.recs->at(index).height:%u \n", vectorRect.recs->at(index).x, vectorRect.recs->at(index).y, vectorRect.recs->at(index).width, vectorRect.recs->at(index).height );
					rectangle(im, vectorRect.recs->at(ii), Scalar(b,g,r), flag, 0, 0);
				}
				//imshow("test", im);
				//waitKey(0);
				//rectangle(im, Rect(70,70,50,50), Scalar(0,0,0), flag, 0, 0);

				

				wakeup(3, 3); // wake-up original process
				break;
			}
			case IMSHOW:{
                                printf("[DEBUG][3] imshow() requested!\n");
				//void * im_p;
				char param[128];
				readparam(3, 0, param);
				//readparam_mat(3, 0, &im_p);
                                //Mat im = Mat(720, 1280, 0, im_p); // TODO: we should be able to retrieve a certain Mat object by its m_handle		
				printf("[DEBUG] param:%s; im.data:%lx; im.total:%u \n", param, im.data, im.total());
				imshow(param, im);
				//char c = waitKey(0);
                		//if (c == 27 || c == 'q')
                        	//	break;
				printf("[DEBUG] imshow completed!\n");
				wakeup(3,3);
				break;
			}

			case WAITKEY__:{
				printf("[DEBUG][3] waitKey() requested!\n");
                                int c = waitKey(10);
				sendparam(0,0,4,&c);
                                wakeup(3,3);
                                break;

					 }

			default:
                                printf("[DEBUG][3] I didn't understand the command...\n");
                                break;
                }
                //break;

        }
        printf("[DEBUG][2] end of execution!\n");

	return 0;

}
