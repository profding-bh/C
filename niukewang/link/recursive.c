#include<stdio.h>


int foo(int x,int y)
{
   if(x<=0 || y <=0)
	return 1;
	return 3*foo(x-6,y/2);
}



int main()
{
   printf("%d\n",foo(20,13));
	return 0;
}












