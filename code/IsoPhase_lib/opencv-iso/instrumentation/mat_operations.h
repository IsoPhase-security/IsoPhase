#ifndef __MATOP_HEADER__
#define __MATOP_HEADER__
#include "shmem.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
extern int g_shmid ;
extern char *g_model_ptr; //point to the shared mem that stores the model data
extern int g_index;
extern char *g_shmem_ptr; // point to the data body in the shared memory
extern char *g_free_ptr; // point to the beginning address of the data body's free space
extern bool instru_flag;
extern char *g_table_ptr ; // point to the data table in the shared memory
extern char *g_table_free_ptr;//point to beginning of the data table's free space

inline void mat2shared(cv::Mat img,int index)//type = 1; index=?
{
	if(index>g_index)
	{
		std::cout<<"index not exist\n"<<std::endl;
	}
	else if(index==-1)
	{
		index=g_index;
		img.buf_index=index;
		g_index++;
		char *tmp_p = g_free_ptr;
		int rows = img.rows;
		int cols = img.cols;
		int channels = img.channels();
		int type = img.type();
		int length=img.total()*img.channels();
		memcpy(tmp_p,&rows,sizeof(int));
		memcpy(tmp_p+4,&cols,sizeof(int));
		memcpy(tmp_p+8,&channels,sizeof(int));
		memcpy(tmp_p+12,&type,sizeof(int));
		memcpy(tmp_p+16,img.data,length);
		shm_element matrecord;
		matrecord.dataindex=index;
		matrecord.offset=tmp_p-g_shmem_ptr;
		matrecord.datalength=length;
		matrecord.datatype=1;
		memcpy(g_table_free_ptr,&matrecord,16);
		g_free_ptr = g_free_ptr + matrecord.offset;
		g_table_free_ptr = g_table_free_ptr + 16;
		
	}
	else
	{
		char *tmp_ptr = get_table_addr(index);
		shm_element * tmp_record = (shm_element *) tmp_ptr;
		int offset = tmp_record->offset;
		char * data_ptr = g_shmem_ptr+offset;
		int rows = img.rows;
		int cols = img.cols;
		int channels = img.channels();
		int type = img.type();
		int length=img.total()*img.channels();
		memcpy(data_ptr,&rows,sizeof(int));
		memcpy(data_ptr+4,&cols,sizeof(int));
		memcpy(data_ptr+8,&channels,sizeof(int));
		memcpy(data_ptr+12,&type,sizeof(int));
		memcpy(data_ptr+16,img.data,length);
	}	
}
inline cv::Mat * matfromshared(int index)
{
	char *tmp_ptr = get_table_addr(index);
	shm_element * tmp_record = (shm_element *) tmp_ptr;
	int offset = tmp_record->offset;
	char * data_ptr = g_shmem_ptr+offset;
	int cols, rows, channels, type;
	memcpy(&rows,data_ptr,4);
	memcpy(&cols,data_ptr+4,4);
	memcpy(&channels,data_ptr+8,4);
	memcpy(&type,data_ptr+12,4);
	int sizeobj=rows*cols*channels;
	void *obj=malloc(sizeobj);
	memcpy(obj,data_ptr+16,sizeobj);

	instru_flag = true;// add instru flag
	cv::Mat *tmp_mat=new cv::Mat(rows,cols,type,obj);
	instru_flag = false;

	return tmp_mat;
}	
#endif 