/*
 =====================================================================================
        Filename:  exit_example.c
     	Description:  
        Version:  1.0
        Created:  2016年07月04日 11时04分07秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
    pid_t pid;
   if(-1 == (pid = fork()))
   {
    perror("fail to create a new process");
    exit(-1);
    }else if(0 == pid ){
      printf("child\n");
      printf("child content in buffer");
      exit(0);
    } else{
      printf("\n parent\n");
      printf("parent content in buffer");
      _exit(0);
    }
    return 0;
}
