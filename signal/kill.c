#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/* 
父进程利用kill函数向其子进程发送一个SIGABRT信号.使子进程非正常结束.
 */


int
main()
{
	pid_t pid;
	int status;
	if( !(pid = fork()))
    {
		printf("child\n");
		sleep(5);
		printf("child again\n");
		return 1;
	}else{ // parent 
		printf("parent send signal to child process(%d)\n",pid);
		sleep(1);
		if(kill(pid,SIGABRT) == -1 )//send SIGABRT to child pid
			printf("kill failure\n");
		wait(&status);//wait for child pid
		// printf("status is %d\n",status);
		if(WIFSIGNALED(status))
			printf("child process receive signal %d\n",WTERMSIG(status));
	}
	return 0;
}

/*

WIFSIGNALED
WIFSIGNALED(status)如果子进程是因为信号而结束则此宏值为真

WTERMSIG
WTERMSIG(status)取得子进程因信号而中止的信号代码，一般会先用WIFSIGNALED来判断后才使用此宏


*/


