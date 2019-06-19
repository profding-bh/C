#include <arpa/inet.h>
#include <stdio.h>

/*
 * uint32_t ntohl(uint32_t netlong); 
 * netlong: 一个以网络字节序表达的32位数
 * 需要引入头文件：#include <arpa/inet.h>
 * 功能：将一个32位数由网络字节序（大端方式） 转换成主机字节序（小端方式）
 *
 *
 *
 *
 *
 *
 *
 */
int main()
{
	uint32_t a = ntohl(0x12345678);
	printf("a is 0x%x\n",a);// 0x78563412

	uint16_t b = ntohs(0x1234);
	printf("b is 0x%x\n",b);// 0x3412

	
	return 0;
}


