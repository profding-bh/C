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
     int count = 1;
     int child;
     printf("before create son, parent count is %d!\n",count);
//     child = vfork();
    if(!(child = vfork())){
    // child process
    int i;
     for(i = 0;i<100;i++)
     {
          printf("This is son, the i is %d\n",i);
            if(70 == i){
                exit(1);
            }
     }
     printf("I am child process, the count is %d, my process ID %d ,my parent process ID is %d\n", ++count,getpid(),getppid());
     exit(1);
    }  else {
        printf("after son, I am parent process, the count is %d, my process ID %d ,the child is %d\n", count,getpid(),child);
     }
     return 0;
}				/* ----------  end of function main  ---------- */
