#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>



/*

当终端没有产生 SIGINT(ctrl+c),
或者SIGQUIT(ctrl+\)信号时, 程序能很好的执行
read函数.即读入终端输入的字符串;
当SIGINT或 SIGQUIT 信号产生时,进程被信号中断.
read出错退出了.

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
	sigemptyset(&act.sa_mask);// 信号集处理函数,将act.sa_mask所指向的信号集清空
	//也就是不包含任何信号
	sigaddset(&act.sa_mask,SIGQUIT);// 只阻塞对SIGQUIT信号的处理
	
	sigaction(SIGINT,&act,NULL); // 注册SIGINT信号 2

	
	do{
		iRet = read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);//从stdin读入数据
		if(iRet < 0){
			perror("read fail");// read fail: Interrupted system call
			break;// read出错,退出
		}

		szBuf[iRet] = 0; // '0' == 48    '\0' == 0
		printf("Get:%s",szBuf);// 打印输出		\n是被读取进字符串中
	}while( strcmp(szBuf,"quit\n") != 0 );//输入'quit'时退出程序
	
	//printf("\n");
	return 0;
}


