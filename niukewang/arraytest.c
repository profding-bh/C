#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int
main()
{
	int a[5] = {1,3,5,7,9};
	int i = 0;
	for(i=0;i<5;++i)
		printf("%p\n",&a[i]);
	printf("%ld\n",sizeof(int));
	printf("%p,%p,%p\n",&a,&a[0],a);
	printf("%p,%p,%p\n",&a+1,&a[0]+1,a+1);
	return 0;
}
