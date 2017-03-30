/*
 =====================================================================================
        Filename:  multipleof3or5.c
     	Description:  3 or 5's multiple
        Version:  1.0
        Created:  2016年05月10日 21时25分18秒
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
   int i,sum = 0;
   for(i =3;i<1000;++i){
      if(i%3 == 0 || i%5 == 0){
          sum += i;
      }
   }
   printf("sum is %d\n",sum);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

