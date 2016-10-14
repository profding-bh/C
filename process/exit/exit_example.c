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

int main(void){
    printf("this process will exit\n");
    exit(0);
    printf("never be excuted\n");
    return 0;
}
