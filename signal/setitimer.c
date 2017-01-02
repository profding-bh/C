#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/* 
alarm函数:将alarm的时间参数设置为5s,5s之后调用信号处理函数
 */


void 
handler()
{
	printf("signal handler func\n");//第5s之后执行
	
}
int
main()
{
	int i;
	signal(SIGALRM,handler);
	alarm(5);
s
	for(i = 1;i<7;++i)
	{
		printf("sleep:%d...\n",i);
		sleep(1);
	}
	return 0;
}



