#include<stdio.h>
#include<unistd.h>
#include<sys/timeb.h>


long getSystemTime()
{
	struct timeb t;
	ftime(&t);
	return 1000*t.time+t.millitm; // ms
}

int
main()
{
	long start,end;

	struct timeb cur;
	ftime(&cur);
	printf("cur timestamp is %ld\n",cur.time);
	start =	getSystemTime();

	sleep(3);
	
	end = getSystemTime();
    
//ms
	printf("ms is %ld\n",end-start);	
	return 0;
}
