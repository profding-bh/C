#include<signal.h>
#include<stdio.h>
#include<stdlib.h>


void
signHandler(int iSignNo,siginfo_t* pInfo, void* pReserved)
{
	printf("信号是 is %d\n",iSignNo);//信号ID 如何变成 信号字符串？？（应该有函数的！）
}



int
main()
{
	struct sigaction act;
	act.sa_sigaction = signHandler;
	act.sa_flags = SA_SIGINFO;//表明信号处理函数由sa_sigaction指定
	sigemptyset(&act.sa_mask);// 信号集处理函数,将act.sa_mask所指向的信号集清空
	//也就是不包含任何信号
	
	sigaction(SIGINT,&act,NULL); // 注册SIGINT信号 2
	sigaction(SIGQUIT,&act,NULL);// 注册SIGQUIT信号 3


	for(;;)
	{

	}
	return 0;
}
