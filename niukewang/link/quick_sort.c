#include<stdio.h>
#include<math.h>

void print_array(int a[],int n);

void quick_s(int a[],int s,int e)
{
	int i = s,j = e; // 保存起始下标和最后一个下标。
	int key = a[s]; //  保存本次比较的基准元素：也就是起始元素。
    int temp;

	// 必须要，递归结束条件。
	if( s > e || !a ) return;

	// 分别从两头开始:
	// i -> j, 找比key 大的元素
	// j -> i ，找比key 小的元素；
	// 交换上面的2个元素
	while(i < j){ // 出口条件：i == j
		while( i < j && a[j] >= key) 
			j--;
		// 此时，a[j] < key
		while( i < j && a[i] <= key) 
			i++;
		// 此时，a[i] > key

		// 交换，a[i] 和 a[j]
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
	// 此时，填基准元素。i==j
	a[s] = a[i]; // 可以这样做是因为，a[s]在一开始的时候已经保存起来了。
	a[i] = key;  // 此时以key作为分界线。左边都比key小，右边都比key大。
	
   print_array(a,e-s+1);
	// 然后递归：
	quick_s(a,s,i-1);
	quick_s(a,j+1,e);
}

void print_array(int a[],int n)
{
	int i;
	for(i = 0;i < n;++i)
		printf("%d ",a[i]);
	printf("\n");
}


int main()
{
	int a[] = {20,15,30,25,50,10,40};
	quick_s(a,0,6);
	//print_array(a,7);
  unsigned int c= 0x12345678;
 unsigned char b = *(unsigned char*)&c;
printf("0x%x\n",b);

printf("%d\n",pow(2,1));
	return 0;
}





