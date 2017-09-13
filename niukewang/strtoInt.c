#include<stdio.h>


typedef enum return_code{
	RC_ERROR = -1,
	RC_SUCCESS = 0,
	RC_NULL_POINTER = 1,
	RC_ILLEGAL_CHAR = 2	
}return_code_t;


int
strToint(const char* str)
{
	int num=0;
	const char* origin = str;

	if(!str){ 
		return RC_NULL_POINTER;
	}

	// 含有非法字符,-,+也只能出现在首位。
	while(*str != 0 ){ 
		if(!((*str >= '0' && *str <= '9') || ( *str == '-') || (*str == '+')) ){// 不是0-9，+，-  
		   return RC_ILLEGAL_CHAR;
		}
		else{
		    ++str;
		}	
	}
	
	str = origin;
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

	//ret = strToint(test);
	//ret = strToint(NULL);
	//ret = strToint("a123");
	ret = strToint("1-23");
	if(ret == RC_ERROR){
		printf("something wrong!\n");
	}else if(ret == RC_NULL_POINTER ){
		printf("参数不合法，空指针\n");
	}else if(ret ==RC_ILLEGAL_CHAR){
		printf("非法字符\n");
	}else {
		printf("the return value is %d\n",ret);
	}
	
	return 0;
}
