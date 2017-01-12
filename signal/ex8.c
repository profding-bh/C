#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

/* 
alarm函数:将alarm的时间参数设置为3s,
 */


void 
handler()
{
	printf("signal handler func\n");
	printf("pid is %d\n",getpid());
	
}
int
main()
{
	int i;
	signal(SIGALRM,handler);
	alarm(3);

	for(i = 1;i<7;++i)
	{
		printf("sleep:%d...\n",i);
		sleep(1);
	}
	return 0;
}



