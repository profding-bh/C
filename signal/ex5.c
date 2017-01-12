#include<signal.h>
#include<stdio.h>

/* 
父进程利用kill函数向其子进程发送一个SIGABRT信号.使子进程非正常结束.
 */


int
main()
{
	pid_t pid;

	if( !(pid = fork()))
    {
		printf("child\n");
		sleep(5);
		printf("child again\n");
		return 1;
	}else{ // parent 
		printf("parent send SIGABRT signal to child process(%d)\n",pid);
		sleep(1);
		if(kill(pid,SIGABRT) == -1 )//send SIGABRT to child pid
			printf("kill failure\n");
	}
	return 0;
}




