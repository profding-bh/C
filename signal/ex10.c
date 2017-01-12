#include<signal.h>
#include<stdio.h>
#include<unistd.h>


void
signHandler(int isigno)
{
	printf("signal:%d\n",isigno);
}

int
main()
{
	signal(SIGALRM,signHandler);// SIGALRM 14
	alarm(4);// 4s,之后触发

	printf("before pause().\n");
	pause();
	printf("After pause().\n");
	return 0;
}
