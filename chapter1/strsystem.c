#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int
main()
{
	int result;
	result = system("exec ls -l"); // 不要exec也可以！
	if( !WIFEXITED(result) )
		printf("abnormal exit!\n");
	_exit(0);
}
