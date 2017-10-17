
#include<stdio.h>

struct a
{
	
};

class b
{
};


class c{
c(){}
~c(){}
};


class d{
d(){}
virtual ~d(){}
};

int 
main()
{
    printf("%d\n",sizeof(a));	//1
	printf("%d\n",sizeof(b));	//1
	printf("%d\n",sizeof(c)); // 1
	printf("%d\n",sizeof(d)); // 4
	return 0;
 } 
