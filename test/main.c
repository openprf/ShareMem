#include <stdio.h>
#include <stdlib.h>
#include "sharemem.h"

int main()
{
	char data[] = "Data to share in memory";
    int res;
    char* rdata = NULL;
    printf("Share Memmory lib test\n");
    printf("DATA: %s\n", data);

    res = sharemem_post("/share_test", data, strlen(data));

    printf("Share mem post result %d\n", res);

    if(res>=0){
		rdata = sharemem_get("/share_test", &res);
		printf("Share mem get result %d\n", res);
		if( (rdata != NULL)&&(res>0) ){
			printf("RDATA: %s\n", rdata);
		}
    }

    return 0;
}
