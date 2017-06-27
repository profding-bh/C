#include<stdio.h>
//#include"error.h"
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

int
main()
{	
	int seconds;
	char line[128];
	char message[64];


	while(1){
	   printf("Alarm> \n");
		if( fgets(line,sizeof(line),stdin) == NULL)
			 exit(0);
		printf("%s  %d",line,strlen(line)); // 包含'\n'
		if(strlen(line)<=1) break;
		if( sscanf(line,"%d %64[^\n]",&seconds,message)<2 ){
			fprintf(stderr,"Bad command\n");
		} else{
			sleep(seconds);
			printf("(%d)  %s\n",seconds,message);
		}
	}	
	return 0;
}


