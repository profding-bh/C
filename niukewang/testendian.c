#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>


int
main()
{
    // 测试大小端,
 	int a = 0x12345678;
	// printf("sizeof(int) = %d\n",sizeof(int)); 4

 	printf("%x\n",*(char*)&a);
	printf("[0]0x%x\n",*(char*)&a);
	printf("[1]0x%x\n",*((char*)&a+1));
	printf("[2]0x%x\n",*((char*)&a+2));
	printf("[3]0x%x\n",*((char*)&a+3));


	if(*(char*)&a == 0x12)
		printf("big endian \n");
	else if(*(char*)&a == 0x78)
		printf("little endian \n");
	else 
		printf("Unknown \n");



	a = htonl(a);
	printf("[0]0x%x\n",*(char*)&a);
	printf("[1]0x%x\n",*((char*)&a+1));
	printf("[2]0x%x\n",*((char*)&a+2));
	printf("[3]0x%x\n",*((char*)&a+3));
	return 0;
}
