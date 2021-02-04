
#ifndef __CVTCOLOR_HEADER__
#define __CVTCOLOR_HEADER__

#include "shmem.h"

extern char* g_shmem_ptr;

#include "copy_def.h"


void instr_cvtcolor(cv::Mat &img)
{
	create_shmem();
	
	unsigned int __var_offset = 0;
	char * p = (char*)g_shmem_ptr;

	int rows = img.rows;
	int cols = img.cols;
	int channels = img.channels();
	int type = img.type();
    
	
	MEMAPPEND_INT( rows );
	MEMAPPEND_INT( cols );
	MEMAPPEND_INT( channels );
	MEMAPPEND_INT( type );	
	MEMAPPEND_BUF( img.data, img.total()*img.channels() );


    std::cout<<"cvtColor() mat data is loaded in the shared memory"<<std::endl;
}


#endif 
