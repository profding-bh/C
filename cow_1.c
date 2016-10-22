#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>


void main()
{
	int x = 0; 
	//static int y = 0;
	printf("parent:local value: Virtual Address:%u\n",&x);
	//printf("%d\n",getpid());


	pid_t pd = fork(); 
	
	if(pd>0)
	{

		while(1);
	}  
	else
	{

		while(1);
	}
	exit(0);
}
