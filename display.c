/*
 =====================================================================================
        Filename:  display.c
     	Description:  display its own source code
        Version:  1.0
        Created:  2016年05月09日 10时04分52秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#include	<stdlib.h>
#include<stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    FILE *fp;
 char c;
   fp = fopen(__FILE__,"r");
  do{
       c = getc(fp);
       putchar(c);
  }

  while(c != EOF);
  fclose(fp);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

