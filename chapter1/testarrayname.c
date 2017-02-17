#include<stdio.h>
#include<stdlib.h>


#define   MAX_NAME_LENGTH              3 //名字的最大长度。
typedef   char             NAME_TYPE[MAX_NAME_LENGTH];
typedef   NAME_TYPE        PROCESS_NAME_TYPE;


int main()
{
	int i;
     PROCESS_NAME_TYPE  PROCESS_NAME[MAX_NAME_LENGTH]= {{"a"},{"b"},{"c"}};//="a";
	//for( i = 0; i < MAX_NAME_LENGTH;++i )
	//	(*(PROCESS_NAME+i)) = "a";

	for(i = 0; i < MAX_NAME_LENGTH;++i )
		printf("PROCESS_NAME[%d]  = %s\n",i,PROCESS_NAME[i]);
	//printf("PROCESS_NAME  = %s\n",PROCESS_NAME);
    return EXIT_SUCCESS;
}
