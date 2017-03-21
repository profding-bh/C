#include<stdio.h>


FILE *stream;


int judge(int a)
{
  	int h = 0,sum = 0;
	int r = 0; 
    h = a/3;//åæ
    r = a%3+h;// 剩余空瓶子的个数
	sum = h;// 总喝水的瓶子数
    while( r >=3 ) //只要大于3瓶，换瓶子的行为才继续。这是关键步骤。 
	{
		h = r/3;
		sum += h;
		r = r%3+h;
    }//
	
	switch(r)
	{
		case 0:break;
		case 1:break;
		case 2:
		sum += 1;break;
	}
	return sum;
}


int
main()
{
	int a = -1;
//	stream=fopen("a.txt","r");
//	if(stream == NULL) printf("open error!\n");
//	fseek(stream,0L,SEEK_SET);
	scanf("%d",&a);
//	fscanf(stream,"%d",&a);
	while(a != 0 )
	{
		//printf("%d\n",a);
		printf("%d\n",judge(a));
     	scanf("%d",&a);
  //   	fscanf(stream,"%d",&a);
	}

//	printf("%d\n",a);
	return 0;
}
