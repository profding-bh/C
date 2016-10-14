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
     long  int var=210;
     printf("The current process ID is %d!\n",getpid());
     return 0;
}				/* ----------  end of function main  ---------- */
