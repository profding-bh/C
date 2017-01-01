#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* SIGINT信号的默认处理 */
int
main()
{
	signal(SIGINT,SIG_DFL); 
	
	while(1)
		sleep(1);
	return 0;
}
