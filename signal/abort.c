#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/* 
abort函数
 */


void 
handler()
{
	printf("signal handler func\n");//
	
}


int
main()
{

	signal(SIGABRT,handler); //SIGABRT
	
	for(;;)
	{
		printf("sleep...\n");
		sleep(1);
	}
	return 0;
}



