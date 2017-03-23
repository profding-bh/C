#include<stdio.h>
#include<time.h>
#include<unistd.h>

int
main()
{
// 一般来说，只要求精确到s的话，time是很好使用的.
	time_t  start,end;// long

	start = time(NULL);
	sleep(3); //time unit:second

	end = time(NULL);
	
// difftime(time1,time0);// time1-time0
	printf("end -start time diff is %lf\n",difftime(end,start));
	printf("start - end time diff is %lf\n",difftime(start,end));
	return 0;
}
