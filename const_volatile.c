#include<stdio.h>
#include<time.h>

int
main()
{
const	volatile  int a = 2;
	// a = 3;
	printf("a = %d\n",a);
	
	time_t rawtime1,rawtime2;

time ( &rawtime1 );

int b;
int i;
	for(  i =1;i<100000000;++i)
		//printf("a = %d\n",a);
		 b = 1;
	time ( &rawtime2 );
	double d = difftime(rawtime2,rawtime1);// ÒÔÃë¼Æ 
	printf("d = %f\n",d);
	return 0;
}
