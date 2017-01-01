#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

/* 

通常情况下，在一个用户进程中需要处理多个信号，
可以在一段程序代码中，定义多个信号的处理函数。
可以是一个信号对应一个特定的处理函数。还可以是多个信号对应同一个处理函数。
 */


void 
sigroutine(int dunno)
{
	switch(dunno){
	 case SIGHUP:printf("Capture SIGHUP signal,the signal number is: %d\n",dunno);break;
	 case SIGINT:printf("Capture SIGINT signal,the signal number is: %d\n",dunno);break;
	 case SIGQUIT:printf("Capture SIGQUIT signal,the signal number is: %d\n",dunno);break;
	}
	return;
}




int
main()
{
	printf("process ID is %d\n",getpid());

	/* 设置3个信号的处理方法 */
	if( signal(SIGHUP,sigroutine) == SIG_ERR ){
		printf("Couldn't register signal handler for SIGHUP\n");
	} 

	if( signal(SIGINT,sigroutine) == SIG_ERR ){
		printf("Couldn't register signal handler for SIGINT\n");
	}
	
	if( signal(SIGQUIT,sigroutine) == SIG_ERR ){
		printf("Couldn't register signal handler for SIGQUIT\n");
	}
	

	
	while(1)
		sleep(1);
	return 0;
}
