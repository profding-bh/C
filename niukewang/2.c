#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int
main()
{
	int a[5] = {1,3,5,7,9};

	for(int i = 0; i<5;++i)
		printf("%p\n",&a[i]);
	printf("a is %p\n",a);
	int *q = a;
	
	int* q2 = (int*)(q+1);
	int* p = (int*)(&a+1); // 是加整个数组，而不是4
	printf(" *p = %d,p is %p\n",*p,p);
	printf(" q2 = %p,*q2 is %d\n",q2,(*q2));
	printf("%d,%d\n",*(a+1),*(p-1));
	return 0;
}
