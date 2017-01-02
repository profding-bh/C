#include<signal.h>
#include<stdio.h>
#include<unistd.h>


/*
使进程模拟睡眠3s,

因为sleep在内部是使用alarm函数来实现的,所以在程序中最好
不要使sleep & alarm混用.

*/
void
signHandler(int isigno)
{
	printf("signal:%d\n",isigno);
}

int
main()
{
	signal(SIGALRM,signHandler);// SIGALRM 14
	alarm(3);// 3s,之后触发

	printf("before pause().\n");
	pause();
	printf("After pause().\n");
	return 0;
}
