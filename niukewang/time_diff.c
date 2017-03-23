#include<stdio.h>
#include<time.h>

int
main()
{

	clock_t start = clock();
// 操作
	for(int i = 0;i<10000;++i)
		;
	clock_t end = clock();
	
	double diff = (double)end - (double)start;
	printf("the running time is:%lfs\n",diff/CLOCKS_PER_SEC); // 秒
	return 0;
}
