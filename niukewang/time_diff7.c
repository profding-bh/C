#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int
main()
{
	clock_t start,finish;
	double duration;
	
	long i,j;

	start = clock();

	sleep(3);// do not affect clock()

	for(i=0;i<100;++i)
	{
		for(j=0;j<10;++j)
		 system("cd");
	}

	finish=clock();

	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	
	printf("Time to do %ld empty loops is ",i*j);
	printf("%lf seconds\n",duration);
	return 0;
}
