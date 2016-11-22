#include<stdio.h>
#include<stdlib.h>

int
main()
{
	char* pPath = getenv("PATH");
	char* pHome = getenv("HOME");
	printf("PATH is %s\n",pPath);
	printf("HOME is %s\n",pHome);
}
