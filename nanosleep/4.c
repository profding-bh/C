#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int flag = 1;

void * thr_fn(void * arg) {
  while (flag){
    printf("******\n");
    sleep(2);
  }
  printf("sleep test thread exit\n");
}
 
int main() {

  pthread_t thread;
  if (0 != pthread_create(&thread, NULL, thr_fn, NULL)) {
    printf("error when create pthread,%d\n", errno);
    return 1;
  }
 
  char c ;
  while ((c = getchar()) != 'q');
 
  printf("Now terminate the thread!\n");
  flag = 0;
  printf("Wait for thread to exit\n");
  pthread_join(thread, NULL);
  printf("Bye\n");
  return 0;
}
