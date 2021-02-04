
#ifndef __DETECTMULTISCALE_HEADER__
#define __DETECTMULTISCALE_HEADER__

#include "shmem.h"

extern char* g_shmem_ptr;

#include "copy_def.h"


cv::Mat * instr_detectMultiScale()
{
	if(instru_flag = false)
	{
		
	}
	create_shmem();
	
	unsigned int __var_offset = 0;
	char * p = (char*)g_shmem_ptr;
	
	
	unsigned int width, height, channels, type;
    
	MEMREAD_UINT( width );
	MEMREAD_UINT( height );
	MEMREAD_UINT( channels );
	MEMREAD_UINT( type );
	
    unsigned int size_obj = width*height*channels;
    void * obj = malloc(size_obj);
	MEMREAD_BUF( obj, size_obj );
    
	// cv::Mat tmp(width,height,type,obj);
	// return tmp;
	return new cv::Mat(width,height,type,obj);
}


#endif 
