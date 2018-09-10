#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	uint32_t a = ntohl(0x12345678);
	printf("a is 0x%x\n",a);
	return 0;
}


