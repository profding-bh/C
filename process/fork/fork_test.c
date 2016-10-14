/*
 =====================================================================================
        Filename:  warning.c
     	Description:  
        Version:  1.0
        Created:  2016年05月18日 11时15分31秒
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
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
     int count = 0;
     pid_t pid;
     pid = fork();
     if(pid < 0)
     {
         printf("error in fork!\n");
         exit(1);
     } else if(0 == pid){
        printf("I am child process, the count is %d, my process ID %d ,my parent process ID is %d\n", count,getpid(),getppid());
     } else{
        printf("I am parent process, the count is %d, my process ID %d \n", ++count,getpid());
     }
     return 0;
}				/* ----------  end of function main  ---------- */
