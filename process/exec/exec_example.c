/*
 =====================================================================================
        Filename:  exec_example.c
     	Description:  14j
        Version:  1.0
        Created:  2016年07月04日 09时39分47秒
        Revision:  none
        Compiler:  gcc
        Author:  Eddyding (), 920398694@qq.com
    	Organization:  BUAA G306
 =====================================================================================
 */

#include<unistd.h>
#include<stdio.h>
#include<errno.h>

int main(void){
    char *envp[] = {"PATH=/tmp","USER=root","STATUS=testing",NULL};
    char *argv_execv[] = {"echo","excuted by execv",NULL};
    char *argv_execvp[] = {"echo","excuted by execvp",NULL};
    char *argv_execve[]={"env",NULL};
    
//由于各个子进程执行的顺序无法控制，所以，有可能出现一个比较混乱的输出
    if(0 == fork()){
      //printf("errno is %d\n",errno);
        // “echo”可以认为是新程序的名字：,随便起，但要有
      if(execl("/bin/echo","echo","excuted by execl",NULL)) // 如果成功，没有返回值，所以perror不会执行
            perror("Err on execl");
    }
    if(0 == fork()){
      if(execlp("echo","echo","excuted by execlp",NULL))
            perror("Err on execlp");
    }
    if(0 == fork()){
      if(execle("/usr/bin/env","env",NULL,envp))
            perror("Err on execle");
    }
    if(0 == fork()){
      if(execv("/bin/echo",argv_execv))
            perror("Err on execv");
    }
    if(0 == fork()){
      if(execvp("echo",argv_execvp))
            perror("Err on execvp");
    }
    if(0 == fork()){
      if(execve("/usr/bin/env",argv_execve,envp))
            perror("Err on execve");
    }
    return 0;
}

