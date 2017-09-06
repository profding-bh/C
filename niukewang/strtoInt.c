#include<stdio.h>


typedef enum return_code{
	RC_ERROR = -1,
	RC_SUCCESS = 0	
}return_code_t;


int
strToint(const char* str)
{
	int num=0;
// char 和int, 比较，char --> int
	while(*str != 0){ // *str  or *str != '\0' or *str != 0 
		num = num*10+*str - '0';
		++str;
	}
	return num;
}


int
main()
{
	char test[] = "123";
	int ret = RC_ERROR;

	ret = strToint(test);
	if(ret == RC_ERROR){
		printf("something wrong!\n");
	}else{
		printf("the return value is %d\n",ret);
	}
	
	return 0;
}
