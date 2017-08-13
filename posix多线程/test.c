#include<stdio.h>
#include<pthread.h>


int
main()
{	
	int a = 1,b = 2, c = 5;

	a -= b - c;// a = a - (b - c); == 4
	printf("a is %d\n",a);// 4
	return 0;
}


