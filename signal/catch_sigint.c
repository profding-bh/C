#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*   捕获终端键入ctrl+c，产生的SIGINT信号。*/

void 
signalHandler(int signum)
{
	printf("Capture signal number:%d\n",signum); // ctrl+\ SIGQUIT信号.
	//exit(1);直接退出了.
}


int
main()
{
//	signal(SIGINT,signalHandler); ctrl+c
	signal(2,signalHandler);//don't use like this.
	while(1)
		sleep(1);
	return 0;
}
