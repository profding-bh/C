#include <stdio.h>
#include <time.h> /* Needed for struct timespec */

int main()
{
   struct timespec tim, tim2;
   tim.tv_sec = 1;
   tim.tv_nsec = 500000000L;

   //if(nanosleep(&tim , &tim2) < 0 )   
 //  {
   //   printf("Nano sleep system call failed \n");
   //   return -1;
  // }
   if(nanosleep(&tim , NULL) < 0 )   
   {
      printf("Nano sleep system call failed \n");
      return -1;
   }

   printf("Nano sleep successfull \n");

   return 0;
}
