/*
 =====================================================================================
        Filename:  3.c
     	Description:  显示文件名
        Version:  1.0
        Created:  2016年05月09日 09时52分45秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#include<stdlib.h>
#include<stdio.h>


// 返回码
enum RET_CODE { 
	OK = 0,
	NOTHING = 1, 
	IOERR = -1,
	CLOSED = -2, 
	BUFFER_FULL = -3, 
	BUFFER_EMPTY = -4, 
	TRY_AGAIN 
};
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
   printf("%s\n",__FILE__);
   printf("TRY_AGAIN = %d\n",TRY_AGAIN);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

