#ifndef COMMON_H
#define COMMON_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <linux/futex.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <limits.h>
#include <map>

//#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/wait.h>

using namespace cv;
using namespace std;
// char * obj; // TODO: must create shared memory where objects will be passed across processes
const int COMMAND_SIZE = 2; //byts
const int FUTEX_WORD_SIZE = 4; //bytes
const int META_INFO_SIZE = 14;
const int PARAMETER_SIZE = 128;

struct mat_info{
	unsigned int width;
	unsigned int height;
	unsigned int channels;
	unsigned int extra;
};

static long sys_futex(void *addr1, int op, int val1, struct timespec *timeout, void *addr2, int val3);

int getshared(bool create);

void receivecommand(unsigned short * incoming, int phase);

void sendcommand(unsigned short command, int phase);

void copy_obj2(int pid, map<unsigned long, size_t> sizes_map); //TODO: actually never used

void copy_rects2shared(vector<cv::Rect> rects);

void copy_mat2shared(Mat im);

void sendparam(int index, char origin, int size, void * param);

void readparam(int pid, int index, void * param);

mat_info readparam_mat(int pid, int index, void * param);

void readparam_rects(int pid, int index, void * param);

void request_copy(int pid, int index, int command);

void sendhandle(void * ref, int phase);

void * receivehandle(int phase);

void wakeup(int pid, int phase);

void makesleep(int pid, int phase);


#endif
