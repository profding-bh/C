
/************************************************************************************************/
/***
	nanosleep函数的使用
	
		ls = (1000)ms
		1ms = (1000)us
		1us = (1000)ns
**/
/***********************************************************************************************/
#include <stdio.h>
#include <unistd.h>
//#include <linux/time.h>
#include <time.h>
#include<sys/time.h>



int main()
{
	int i = 0;
	struct timespec t = {.tv_sec = 0,.tv_nsec = 0};
	struct timeval t2;
	
	
	while(1)
	{
		gettimeofday(&t2, NULL);//
		//  t2.tv_sev;//seconds
		//TIMEVAL_TO_TIMESPEC(t2, t);
		//printf("time %ld:%lu\n",t2.tv_sec,t2.tv_usec);
		t.tv_sec = t2.tv_sec;
		t.tv_sec += 1;
		t.tv_nsec += 0;
		printf("%d\n", ++ i);
		nanosleep(&t, NULL);
	}

}


