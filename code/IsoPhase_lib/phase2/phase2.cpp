#include "../common.h"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

enum phase2commands{ CASCADE_LOAD, CASCADE_DETECTMULTISCALE, VECTORRECT_SIZE};

using namespace cv;
int main(){
	std::map<unsigned long, size_t> sizes_map; // data structure to store the size of continuous objects //TODO: add sizes of all obtained objects
	unsigned int obj_size;
	unsigned short command; 
	getshared(0);
        while(1){
		makesleep(2, 2); //phase2 sleep on futex2
		printf("\n");
        	receivecommand(&command, 2); // read string command 
                printf("[DEBUG][2] this is what I got: %d...\n", command);
		if (command == 400) break;
                switch(command){
                        case CASCADE_LOAD:{
                                printf("[DEBUG][2] CascadeClassifier::load() requested!\n");
                                CascadeClassifier * cascade = new CascadeClassifier();
				char param[128];
			       	readparam(2, 0, param);
				printf("[DEBUG][2] param is %s\n", param);
				cascade->load(param);
				printf("[DEBUG][2] Cascade classifier created! Sending handle (it should be: %lx)\n", cascade);
				sendhandle(cascade, 2);
                                wakeup(2, 2); // wake-up original process
                                break;
                                          }
			case CASCADE_DETECTMULTISCALE:{
				printf("[DEBUG][2] CascadeClassifier::detectMultiScale() requested!\n");
				void * m_handle = receivehandle(2);
				CascadeClassifier * cascade = ((CascadeClassifier*) m_handle);
				printf("[DEBUG] cascade:%lx\n", cascade);	
				void * p_im;
				printf("[DEBUG][2] newly created p_im:%lx\n", p_im);

				// request Mat param

				mat_info meta = readparam_mat(2, 0, &p_im);
				printf("[DEBUG][2] readparam completed!\n"); 
				printf("[DEBUG][2] received pointer is p_im:%lx\n", p_im);
				Mat im = Mat(meta.width, meta.height, 0, p_im);
				printf("[DEBUG][2] im.rows: %u; im.cols: %u\n", im.rows, im.cols);
				//imshow("a window", im);
				//waitKey(0);
				
				// request other params
				double scale;
				int minNeighbors;
				int flags;
				int width, height;
				readparam(2, 2, &scale);
				printf("[DEBUG][2] scale: %f\n", scale);
				readparam(2, 3, &minNeighbors);		
				printf("[DEBUG][2] minNeighbors: %d\n", minNeighbors);
				readparam(2, 4, &flags);
				printf("[DEBUG][2] flags: %d\n", flags);
				readparam(2, 5, &width);
				printf("[DEBUG][2] width: %d\n", width);
				readparam(2, 6, &height);		
				printf("[DEBUG][2] height: %d\n", height);
			
				std::vector<Rect> faces;			

				cascade->detectMultiScale(im, faces, scale, minNeighbors, flags, Size(width, height));
				//obj_size = sizeof(faces);
				sizes_map[(unsigned long) faces.data()] = sizeof(cv::Rect)*faces.size(); // sure-fire way to get the correct size of data
				printf("[DEBUG][2] &faces: %lx; faces.data: %lx; sizeof(cv::Rect)*faces.size(): %lu; faces.size():%u\n", &faces, faces.data(), sizeof(cv::Rect)*faces.size(), faces.size());
				for (int ii = 0; ii < faces.size(); ii++){
					printf("[DEBUG][2] faces.at(0).x:%u; faces.at(0).y:%u; faces.at(0).width:%u; faces.at(0).height:%u; \n", faces.at(ii).x, faces.at(ii).y, faces.at(ii).width, faces.at(ii).height);
					 //printf("[DEBUG][2] &faces.at(0).x:%lx\n", &faces.at(0).x);
				}
				sendhandle(faces.data(), 2); 
				copy_rects2shared(faces);
				wakeup(2, 2); // wake-up original process
                                break;
						      }	
			case VECTORRECT_SIZE:{
				printf("[DEBUG][2] Vector<Rect>::size() requested!\n");
                                void * m_handle = receivehandle(2);//TODO: m_handle should be global
				printf("[DEBUG][2] m_handle: %lx; sizes_map[(unsigned long) m_handle]: %lx!\n", m_handle, sizes_map[(unsigned long) m_handle]);
                                std::vector<Rect> vec_rec( (Rect *) m_handle, (Rect *) (m_handle + sizes_map[(unsigned long) m_handle]) ); //reconstruct vector
                                int size = vec_rec.size();
                                //printf("[DEBUG][2] vec_rec.size():%d; vec_rec.at(0).x:%u\n", size, vec_rec.at(0).x);
                                sendparam(0,0,sizeof(int),&size); // return value
                                wakeup(2, 2); // wake-up original process
				break;
                                             }

			case 997:{ //copy vector<Rect>
				printf("[DEBUG][2] copy_rects2shared(int,std::vector<Rector>) is deprecated()!\n");
                                //void * m_handle = receivehandle(2);//TODO: m_handle should be global
                                //std::vector<Rect> recs( (Rect *) m_handle, (Rect *) (m_handle + sizes_map[(unsigned long) m_handle]) ); //reconstruct vector
				//printf("[DEBUG][2] recs.at(0).x:%u; &recs.at(0).x:%lx\n",recs.at(0).x, &recs.at(0).x);
                                //copy_rects2shared(2, recs);
				wakeup(2,2); // wake other process sleeping on futex
                                break;


				 }
			case 998:{ // called by readparam_mat
					break;
				 }

			case 999: {//copy_obj2
			  	printf("[DEBUG][2] Object copy requested!\n");
                                copy_obj2(2, sizes_map); 
                                wakeup(2,2); // wake other process sleeping on futex
                               	break;
				  }
                        default:
                                printf("[DEBUG][2] I didn't understand the command...\n");
                                break;
                }
                //break;

        }
        printf("[DEBUG][2] end of execution!\n");

	return 0;
}
