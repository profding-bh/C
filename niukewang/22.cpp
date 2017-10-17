#include<stdio.h>
#include<math.h>
 
int
main()
{
	int a,b;
	int i;
	
	
	while( scanf("%d%d",&a,&b) != EOF)
	{
		if(a = 1 && b == 1)  
		  {
		  	printf("%d\n",0); continue;
		  }
		if(b != 2 && b != 4 && b != 6 && b != 8  && b != 0) 
		 printf("%d\n",-1);
		else  
		  printf("%d\n",1);
		
	}


   return 0;
 }  
