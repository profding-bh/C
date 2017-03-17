#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int
main()
{
	int a[5] = {1,3,5,7,9};
        int i;
	for( i = 0; i<5;++i)
		printf("%p\n",&a[i]);
	printf("a is %p\n",a);
	int *q = a;
	
	int* q2 = (int*)(q+1);
	int* p = (int*)(&a+1); // 是加整个数组，而不是4
	int* p3 = (int*)(a+1); // 是加4，而不是 整个数组!!!好tricky.

// &a+1 和 a+1是不一样的。
// &a+1 是加整个数组，而a+1，是指针加4（8）

	printf(" q2 = %p,*q2 is %d\n",q2,(*q2));
	printf(" *p = %d,p is %p\n",*p,p);
	printf(" *p3 = %d,p3 is %p\n",*p3,p3);


	printf("%d,%d\n",*(a+1),*(p-1));
	return 0;
}
