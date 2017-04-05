#ifndef SHAREMEM_H_INCLUDED
#define SHAREMEM_H_INCLUDED

/**
@info Shared memorty library
@autor Aleksy Afanasiev
@date 05.04.2017
**/

#ifdef __cplusplus
extern "C"
{
#endif

/**
\brief Creat shared memmory, and copy data there

@param mem_name  - name of shared memory block
@param data_ptr - pointer to data
@param data_size - size of data
retrun shared memory desrioter or error code (if value less 0)
**/
int sharemem_post(char* mem_name, void* data_ptr, int data_size);

/**
\brief Get shared memmory pointer
@param mem_name  - name of shared memory block
@param data_size - variable caring size of chared memory data block or error code (if value less 0)
retrun pointer to shared memory
**/
char* sharemem_get(char* mem_name, int* data_size);

/**
\brief destroy of shared memory block
@param mem_name  - name of shared memory block
retrun RESERVER 
**/
int sharemem_free(char* mem_name);
#ifdef __cplusplus
}
#endif

#endif // SHAREMEM_H_INCLUDED
