#include<signal.h>
#include<stdio.h>
#include<stdlib.h>


void
signHandler(int isigNum)
{
	printf("SIGQUIT is %d\n",isigNum);
	exit(1);
}


int
main()
{
	signal(SIGQUIT,signHandler);


	for(;;)
	{

	}
	return 0;
}
