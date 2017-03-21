
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[5] = {1,3,5,7,9};
	printf("%d\n",sizeof(int));
	printf("%p,%p,%p\n",&a,&a[0],a);// a 和 &a 进行指针运行，就不一样了。
	printf("%p,%p,%p\n",&a+1,&a[0]+1,a+1);
	//system("pause");
	
}
