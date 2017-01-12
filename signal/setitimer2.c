#include<signal.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>


/* 
setitimer函数:使用setitimer函数产生SIGALRM信号.
*/

static void
elsfTimer(int signo)
{
	struct timeval tp;
	struct tm* tm;
	gettimeofday(&tp,NULL); //gettimeofday函数获得系统当前时间(s & us)
	tm = localtime(&tp.tv_sec);// localtime取得当地目前时间和日期
	
	printf("sec = %ld\t",tp.tv_sec);// 打印从UNIX纪元开始到现在的秒数
	printf("usec = %ld\t",tp.tv_usec);//
	printf("%d-%d-%d %d:%d:%d\n",
	tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,
	tm->tm_hour,tm->tm_min,tm->tm_sec); //打印当地目前时间和日期
}


static void
initTime(int tv_sec,int tv_usec)
{
	struct itimerval value;

	signal(SIGALRM,elsfTimer);
	value.it_value.tv_sec = tv_sec;// 首次启动的时间
	value.it_value.tv_usec = tv_usec;
	
	value.it_interval.tv_sec = tv_sec;//间隔时间
	value.it_interval.tv_usec = tv_usec;

	setitimer(ITIMER_REAL,&value,NULL);// setitimer发送信号.定时器类型为ITIMER_REAL
}

/*

gettimeofday


struct tm *localtime(const time_t *timer)


localtime

#ifndef __TIME_T

#define __TIME_T    

typedef long     time_t;   

*/

int
main()
{
	initTime(1,0);
	for(;;)
	{
	}
	return 0;
}



