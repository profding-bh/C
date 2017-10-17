#include<stdio.h>



int main()
{

   int a[] = {-1,0,1,2,-1,4};
	int i,j,k;
	for(i=0;i<6;++i)
{
		for(j=i+1;j<6;++j)
		{
             for(k=j+1;k<6;++k)
		 {
             if(a[i]+a[j]+a[k] == 0)
				printf("[%d,%d,%d]\n",a[i],a[j],a[k]);
		  }
		}
}
	return 0;
}


