
#ifndef __SHMEM_HEADER__
#define __SHMEM_HEADER__

#include <sys/types.h>
#include <sys/shm.h>
#include <iostream>

#define SHAREMEM_DATA_KEY 0xAB
#define SHAREMEM_MODEL_KEY 0xAC
using namespace std;
inline bool instru_flag = false;

inline int g_shmid = 0;
inline char *g_model_ptr = (char *)0; //point to the shared mem that stores the model data
inline int g_index = 0;//index for objects in the shared mem

inline char *g_shmem_ptr = (char *)0; // point to the data body in the shared memory
inline char *g_free_ptr = (char *)0; // point to the beginning address of the data body's free space

inline char *g_table_ptr = (char *)0; // point to the data table in the shared memory
inline char *g_table_free_ptr = (char *)0;//point to beginning of the data table's free space

inline bool g_bCreated = false; // flag for create shared memory
inline bool g_bFreed = true; // flag for free shared memory

inline int mat_size = 1280*721*3;// default resolution is 720 and extra for mat information

struct shm_element
{
	int dataindex;//the token represents the variable;
	int offset;//point to the beginning of the data
	int datalength;//record the datalength;
	int datatype;//record the data type Mat,Rect and so on
};//size 16
inline void create_shmem()
{
	if( g_bCreated == false ) {
		key_t key = SHAREMEM_DATA_KEY;
		g_shmid = shmget(key, 1024*10270*3, IPC_CREAT|0666);
		g_shmem_ptr = (char *) shmat(g_shmid, (void *) 0, 0);
		g_table_ptr = g_shmem_ptr;
		g_table_free_ptr=g_table_ptr;
		int offset = 800;//space for maintain 50 records
		g_shmem_ptr = g_table_ptr + offset;
		g_free_ptr = g_shmem_ptr;
		g_bCreated = true;
		g_bFreed = false;
	}
}
inline void free_shmem()
{
	if(g_bFreed == false)
	{
		shmctl(g_shmid,IPC_RMID,NULL);
		g_bCreated = false;
	}

}
inline char * get_table_addr(int index)
{
	if(index>g_index){
		std::cout<<"index not exists\n"<<std::endl;
	}
	char *shm_element = g_table_ptr + index*16;
	return shm_element; 

}
inline int get_channel_num(int type)
{
	int channels = type/8 + 1;
	return channels;
}
inline void create_mat_shmem(int length, void *data = (void *)0)
{
	create_shmem();
	shm_element new_record;

	

	new_record.dataindex = g_index;
	g_index = g_index + 1;

	char *current_data_ptr = g_free_ptr;
	new_record.offset= current_data_ptr - g_shmem_ptr;

	new_record.datalength = length;
	new_record.datatype = 1;
	
	g_free_ptr = g_free_ptr + length;
	
	memcpy(g_table_free_ptr,&new_record,16);
	g_table_free_ptr = g_table_free_ptr + 16;

}

#endif 
