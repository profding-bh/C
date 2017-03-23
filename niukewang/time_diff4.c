#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

int
main()
{
	struct timeval start,end;
	gettimeofday(&start,NULL);

	sleep(3);
	
	gettimeofday(&end,NULL);
    
// us:微秒
	int us = 1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);

	printf("us is %d\n",us);	
	return 0;
}
