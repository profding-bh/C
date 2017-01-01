#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*  忽略SIGINT信号，ignore_sigint.c  */

int
main()
{
	signal(SIGINT,SIG_IGN); //ctrl+c 不起作用,ctrl+\:quit
	
	while(1)
		sleep(1);
	return 0;
}
