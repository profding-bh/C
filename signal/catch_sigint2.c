#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*   捕获终端键入ctrl+c，产生的SIGINT信号。*/

void 
signalHandler(int signum)
{
	printf("Capture signal number:%d\n",signum); // ctrl+\ SIGQUIT信号.
}

void 
signalHandler2(int signum)
{
	printf("2222 Capture signal number:%d\n",signum); // ctrl+\ SIGQUIT信号.
}


int
main()
{
	signal(SIGINT,signalHandler); //ctrl+c
/* signalHandler 自动被覆盖了 */
	signal(SIGINT,signalHandler2); // ctrl+c

	while(1)
		sleep(1);
	return 0;
}
