#define MaxSize 1000

#include<stdio.h>

typedef int ElemType;

ElemType A[MaxSize];
int n;



void ERRORMESSAGE(const char* str)
{
	printf("%s",str);
}

void insertlist(ElemType A[],int &n, int i,ElemType item)
{
	int j;
	if(n == MaxSize || i < 1 || i > n+1)
	{
		ERRORMESSAGE("表满或插入位置不正确");
	}
	for(j=n-1;j>=i-1;j--)
		A[j+1]=A[j];
	A[i-1]=item;
	n++;
}


void deletelist(ElemType A[],int &n,int i)
{
  int j; // 下标[0,n-1]
  if( i < 1 || i > n){
		ERRORMESSAGE("表空或删除位置不正确");
	}
// i：位置。[1,n]
  for(j=i;j<n;j++)
	A[j-1]=A[j];

 n--;
}

int locate(ElemType A[],int n,ElemType item)
{
  int i;
 for(i=0;i<n;i++)
	if(A[i] == item)
 	  return i+1; //返回元素在表中的位置。

  return -1;
}
void print_element(ElemType A[],int n)
{
	  int i = 0;
	 for(;i < n; ++i) 
		printf("%d ",A[i]);
	printf("\n");
}




void dedup(ElemType A[],int n)
{

    int i = 0,j;
	while(i<n){
      j=i+1;
	  while(j<n)
	  {
		
      }
   }
}

int main()
{
	ElemType A[]= {1,2,3};
	int n = 3;

	print_element(A,n);
	insertlist(A,n,4,4);
	print_element(A,n);

	deletelist(A,n,1);

    print_element(A,n);
	return 0;
}








