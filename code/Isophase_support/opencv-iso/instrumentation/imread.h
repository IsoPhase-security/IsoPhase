
#ifndef __IMREAD_HEADER__
#define __IMREAD_HEADER__

#include "mat_operations.h"

extern char* g_shmem_ptr;

#include "copy_def.h"

void instr_imread(cv::Mat &img)
{
	
	// create_shmem();
	// mat2shared(img,-1);


	// unsigned int __var_offset = 0;
	// char * p = (char*)g_shmem_ptr;

	// int rows = img.rows;
	// int cols = img.cols;
	// int channels = img.channels();
	// int type = img.type();
	
	
	// MEMAPPEND_INT( rows );
	// MEMAPPEND_INT( cols );
	// MEMAPPEND_INT( channels );
	// MEMAPPEND_INT( type );	
	// MEMAPPEND_BUF( img.data, img.total()*img.channels() );
	
    /*
	memcpy(ptr,    &rows, 4);
	memcpy(ptr+4,  &cols, 4);
	memcpy(ptr+8,  &channels, 4);
	memcpy(ptr+12, &type, 4);
	memcpy(ptr+16, img.data, img.total()*img.channels());
	*/
    std::cout<<"imread() mat data is loaded in the shared memory"<<std::endl;    
}


#endif 
