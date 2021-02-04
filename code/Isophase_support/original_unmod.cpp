#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <chrono>
using namespace std;
using namespace cv;

int main(){
	auto start = std::chrono::system_clock::now();
	printf("[DEBUG] Start of application\n");
	VideoCapture cap = VideoCapture();
	CascadeClassifier cascade;
	cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
	cap.open("/home/marco/Documents/research/one_sec.mp4");
	Mat im;
	vector<Rect> faces;
	//auto milestone = std::chrono::system_clock::now();
	//printf("[DEBUG] Elapsed time before loop:%f\n", (milestone-start).count());
	while (cap.isOpened()){
		auto loop_start = std::chrono::system_clock::now();
		if(!cap.read(im)) break;
		cvtColor(im, im, COLOR_BGR2GRAY, 1);
		auto cap_read_end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_cap_read = cap_read_end-loop_start;
		printf("[DEBUG] time for cap.read(im):%f\n", (elapsed_cap_read).count());

		auto detect_start = std::chrono::system_clock::now();
		cascade.detectMultiScale(im, faces, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30,30));
		auto detect_end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_detect = detect_end-detect_start;
		printf("[DEBUG] time for cascade.detectMultiScale(im):%f\n", (elapsed_detect).count());
		
		auto rectangle_for_start = std::chrono::system_clock::now();	
		for (size_t i = 0; i < faces.size(); i++){
			//Rect rect = faces[i];
			//rectangle(im, cvPoint(rect.x, rect.y), cvPoint(rect.x+rect.width,rect.y+rect.height), color, 3, 10, 0);
			rectangle(im, faces[i], Scalar(255,0,0), 1, 0, 0);
		}
		auto rectangle_for_end = std::chrono::system_clock::now();	
                std::chrono::duration<double> elapsed_rectangle = rectangle_for_end-rectangle_for_start;
		printf("[DEBUG] time for for loop with rectangle():%f\n", (elapsed_rectangle).count());



		auto imshow_start = std::chrono::system_clock::now();	
		imshow("Window",im);
		auto imshow_end = std::chrono::system_clock::now();	
                std::chrono::duration<double> elapsed_imshow = imshow_end-imshow_start;
		printf("[DEBUG] time for imshow():%f\n", (elapsed_imshow).count());
			
		
		char c = waitKey(10);
		if (c == 27 || c == 'q')
			break;
                
		
		auto loop_end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_loop = loop_end-loop_start;
		printf("[DEBUG] time for loop (1 iteration):%f\n", elapsed_loop.count());

		printf("=====================================================================================================\n");

	}	
	auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        printf("[DEBUG][END][END][END] It's over! Elapsed:%f\n", elapsed_seconds.count());

	return 0;
}

