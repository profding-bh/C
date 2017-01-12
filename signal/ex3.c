#include<signal.h>
#include<stdio.h>
#include<stdlib.h>



/*  忽略SIGQUIT信号  */

int
main()
{
	signal(SIGQUIT,SIG_IGN); //ctrl+\没有反应
	
	while(1)
		sleep(1);
	return 0;
}
