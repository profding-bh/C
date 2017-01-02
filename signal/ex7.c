#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* 
sigqueue函数  向自身进程发送一个SIUSR1信号.

 */


void 
sigHandler(int isigno,siginfo_t* info,void* context)
{
	printf("Receive signal number:%d\n",isigno);//10
}

int
main()
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction =  sigHandler;
	
	if(sigaction(SIGUSR1,&act,NULL) == -1)
	{
		printf("sigaction failure\n");
		exit(1);
	}

	sigval_t val;
	if( sigqueue(getpid(),SIGUSR1,val) == -1 )
	{
		printf("sigqueue failed\n");
		exit(1);
	}

	sleep(3);
	return 0;
}
