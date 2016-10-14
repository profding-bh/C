/*
 =====================================================================================
        Filename:  wait_example.c
     	Description:  
        Version:  1.0
        Created:  2016年07月04日 20时00分15秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    pid_t pc,pr;
    if((pc = fork())< 0)
    {
      perror("Err in fork");
      exit(-1);
    }else if(0 == pc){
        printf("Child process ,pid is %d\n",getpid());
        sleep(10);//10s
    }else{
        pr = wait(NULL);//等待
        printf("parent catched a child process %d\n",pr);
    }
    return 0;
}


