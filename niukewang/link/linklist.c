#include<stdio.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
struct node* link;
}LNode,*LinkList;


LinkList create(int n)
{
	LinkList p,r,list = NULL;
	ElemType a;
	int i;
	for(i=1;i<=n;++i){
	   p = (LinkList)malloc(sizeof(LNode));
	   p->data = i;
		p->link= NULL;
		if(NULL == list)
			list=p; // ç¬¬ä¸€ä¸ªèŠ‚ç‚¹
		else
			r->link = p; // ç¬¬2ä¸ªåŠä»¥åçš„èŠ‚ç‚¹
		r=p;
	}
	return list;
}

void print_list(LinkList L)
{
	if(!L) return;
	while(L!= NULL)
	{ 
		printf("%d ",L->data);
		L=L->link;
	}
	printf("\n");
}

// Á´±í·´×ª 
LinkList LinkListReverse(LinkList L)
{
	 if(!L) return (LinkList)-1; 
	 
	 LinkList pcur,ptemp;
	 pcur=L->link;
	 L->link=NULL; 
	 // µ¥¸ö½ÚµãÍ¬Ñù¿ÉÒÔÓÃ 
	 while(pcur != NULL )
	 {
	 	ptemp = pcur->link; // ÄÃµ½ÏÂÒ»¸ö½Úµã 
	 	pcur->link = L; // Í·½Úµã´æÔÚpcur->link  
	 	L = pcur; // pcur³ÉÎªĞÂµÄÍ· 
	 	pcur = ptemp; // pcur±ä³ÉÏÂÒ»¸ö½Úµã 
	  } 
	 return L;  // ĞÂµÄÍ· 
}


int main(void)
{
	LinkList L;
    L =	create(3);
	print_list( L);
	
		L = LinkListReverse(L);
		print_list( L);
	return 0;
}






