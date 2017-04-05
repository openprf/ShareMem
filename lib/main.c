#include "sharemem.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

enum {
	MEM_STATUS_NOT_READY,
	MEM_STATUS_READY,
};

typedef struct _sharemem_hdr{
	int status;
	int len;
	char data[0];
}sharemem_header_t;

int sharemem_post(char* mem_name, void* data_ptr, int data_size)
{
	int sharemem_id = -101;
	sharemem_header_t* shmem;

	if( (sharemem_id = shmget(mem_name, 2*sizeof(int)+data_size, 0666 | IPC_CREAT)) != -1 ){
		if( (shmem =  (sharemem_header_t*)shmat(sharemem_id, NULL,0)) != (char*)-1 ){

			shmem->status = MEM_STATUS_NOT_READY;
			memcpy(shmem->data, data_ptr, data_size);
			shmem->len = data_size;
			shmem->status = MEM_STATUS_READY;

		}else{
			sharemem_id = -102;
		}
	}

	return sharemem_id;
}

char* sharemem_get(char* mem_name, int* data_size)
{
	char* data_prt = NULL;
	*data_size = -1;
	int sharehdr_id;

	if( (sharehdr_id = shmget(mem_name, 2*sizeof(int), 0666)) != -1 ){
		sharemem_header_t* shmemhdr;
		if( (shmemhdr =  (sharemem_header_t* )shmat(sharehdr_id, NULL,0)) != (char*)-1 ){

			if(shmemhdr->status == MEM_STATUS_READY){
				int sharemem_id;
				if( (sharemem_id = shmget(mem_name, 2*sizeof(int)+shmemhdr->len, 0666)) != -1 ){
					sharemem_header_t* shmem;
					if( (shmem =  (sharemem_header_t* )shmat(sharemem_id, NULL,0)) != (char*)-1 ){
						*data_size = shmem->len;
						data_prt = shmem->data;
					}else{
						*data_size = -5;
					}
				}else{
					*data_size = -4;
				}
			}else{
				*data_size = -3;
			}

		}else{
			*data_size = -2;
		}
	}

	return data_prt;
}

int sharemem_free(char* mem_name)
{
	shmdt(mem_name);
}
