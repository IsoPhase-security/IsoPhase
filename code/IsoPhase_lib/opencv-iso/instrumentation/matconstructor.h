#ifndef __MATCONSTRUCTOR_HEADER__
#define __MATCONSTRUCTOR_HEADER__

#include <iostream>
#include "shmem.h"
#include "opencv2/core/matx.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/core/bufferpool.hpp"
#ifdef CV_CXX11
#include <type_traits>
#endif
using namespace std;
extern bool instru_flag;
extern int g_index;

extern int mat_size;// default resolution is 720 and extra for mat information

extern char *g_shmem_ptr; // point to the data body in the shared memory
extern char *g_free_ptr; // point to the beginning address of the data body's free space

extern char *g_table_ptr; // point to the data table in the shared memory
extern char *g_table_free_ptr;//point to beginning of the data table's free space

inline void instru_mat_constructor()
{


    create_mat_shmem(mat_size);
    if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;

    }
        
}

inline void instru_mat_constructor(int _rows, int _cols, int _type)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(int _rows, int _cols, int _type, const cv::Scalar& _s)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(cv::Size _sz, int _type)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(cv::Size _sz, int _type, const cv::Scalar& _s)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(int _dims, const int* _sz, int _type)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(int _dims, const int* _sz, int _type, const cv::Scalar& _s)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(const std::vector<int>& _sz, int _type)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(const std::vector<int>& _sz, int _type, const cv::Scalar& _s)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(const cv::Mat& m)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(int _rows, int _cols, int _type, void* _data, size_t _step)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

inline void instru_mat_constructor(cv::Size _sz, int _type, void* _data, size_t _step)
{
    
if(instru_flag==false)
    {
        std::cout<<"this constructor is called by target application code"<<std::endl;
    }
}

// inline void instru_mat_constructor(const std::vector<_Tp>& vec, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const std::initializer_list<_Tp> list)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const std::initializer_list<int> sizes, const std::initializer_list<_Tp> list)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const cv::Vec<_Tp, n>& vec, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const Matx<_Tp,m,n>& M, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const Point_<_Tp>& pt, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const Point3_<_Tp>& pt, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

// inline void instru_mat_constructor(const MatCommaInitializer_<_Tp>& commaInitializer)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }
//-----------------------------------------------------
// inline void instru_mat_constructor(const Matx<_Tp,m,n>& M, bool copyData)
// {
    
//     if(instru_flag==false)
//         std::cout<<"this constructor is called by instrumentation code"<<std::endl;
// }

#endif 
