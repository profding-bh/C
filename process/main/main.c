/*
 =====================================================================================
        Filename:  main.c
     	Description:  
        Version:  1.0
        Created:  2016年07月04日 08时42分54秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#define aaa

#include<stdio.h>

int main(int argc,char *argv[],char *envp[]){

    printf("argc is %d\n",argc);

    printf("###ARGV#####\n");
    while(*argv){
    printf("%s\n",*argv++);
    }   
   printf("###ENVP######\n");
    
    while(*envp){
    printf("%s\n",*envp++);
    }   
 return 0;
}
