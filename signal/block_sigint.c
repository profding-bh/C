#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>



/*

屏蔽掉SIGINT信号,那么信号处理函数,将不能再捕捉到SIGINT(虽然注册了SIGINT
& SIGQUIT 信号)信号.而只能捕捉到SIGQUIT信号.


*/
int g_iSeq = 0;


void
SignHandlerNew(int iSignNo,siginfo_t* pInfo, void* pReserved)
{
	int iSeg = ++g_iSeq;
	printf("\n%d Enter SignHandlerNew ,signo:%d.\n",iSeg,iSignNo);
	sleep(3);// 3s
	printf("%d Leave SignHandlerNew ,signo:%d.\n",iSeg,iSignNo);
}


int
main()
{
	char szBuf[20];
	int iRet;

	struct sigaction act;
	act.sa_sigaction = SignHandlerNew;
	act.sa_flags = SA_SIGINFO;//表明信号处理函数由sa_sigaction指定
	
	
	// 设置阻塞信号集
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset,SIGINT);// ctrl+c产生的SIGINT信号被sigprocmask设置为;屏蔽了.
	sigprocmask(SIG_BLOCK,&sigset,NULL);


	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);// 注册SIGINT信号 2
	sigaction(SIGQUIT,&act,NULL);// 注册SIGQUIT信号 3
	
	
	do{
		iRet = read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);//从stdin读入数据
		if(iRet < 0){
			perror("read fail");// read fail: Interrupted system call
			break;// read出错,退出
		}

		szBuf[iRet] = 0; // '0' == 48    '\0' == 0
		printf("Get:%s",szBuf);// 打印输出		\n是被读取进字符串中
	}while( strcmp(szBuf,"quit\n") != 0 );//输入'quit'时退出程序
	
	return 0;
}


