#include<stdio.h>

int 
main()
{
	int a,b,c,i,j;
	int flag;

	while(scanf("%d%d%d",&a,&b,&c) != EOF )
	{
		flag = 0;
		for(i=0;i<=c/a;++i)
		{
			for(j=0;j<=(c-a*i)/b;++j)
			{
				if(c ==  a*i + b * j)
				  	flag = 1;
				  	
			}
		}
		
       if(flag == 1)
	      printf("Yes\n");
	    else 
	      printf("No\n");
	 } 
    return 0;
 } 
