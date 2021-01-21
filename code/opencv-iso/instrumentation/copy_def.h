
#ifndef __COPY_DEF_HEADER__
#define __COPY_DEF_HEADER__

#ifndef MEMAPPEND_BUF
#define MEMAPPEND_BUF(__var, __size) \
	memcpy( p + __var_offset, __var, __size );\
	__var_offset += __size;
#endif


#ifndef MEMAPPEND_INT
#define MEMAPPEND_INT(__var) \
	memcpy( p + __var_offset, &__var, sizeof(int) );\
	__var_offset += sizeof(int);
#endif

#ifndef MEMREAD_BUF
#define MEMREAD_BUF(__var, __size) \
	memcpy( __var, p + __var_offset, __size );\
	__var_offset += __size;
#endif


#ifndef MEMREAD_INT
#define MEMREAD_INT(__var) \
	memcpy( &__var, p + __var_offset, sizeof(int) );\
	__var_offset += sizeof(int);
#endif

#ifndef MEMREAD_UINT
#define MEMREAD_UINT(__var) \
	memcpy( &__var, p + __var_offset, sizeof(unsigned int) );\
	__var_offset += sizeof(unsigned int);
#endif


#endif