#include<stdio.h>
#include<time.h>

int
main()
{
    long	int b;

	b = clock()/CLOCKS_PER_SEC; // 0
	printf("b is %ld,CLOCKS_PER_SEC is %ld\n",b,CLOCKS_PER_SEC);
	for(int i = 0; i < 5;++i )//延时5s
	{
//		i = i - b;
		i = clock()/CLOCKS_PER_SEC;
//		printf("i is %d\n",i);
	}
	printf("over\n");
	return 0;
}
