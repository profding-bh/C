#include<stdio.h>
#include<stdlib.h>

int main()
{
   FILE *fp;
   if((fp = fopen("file.c","r")) == NULL){
         printf("打开文件出错\n");
 	exit(1);
  }
  while(!feof(fp)){
   putchar(fgetc(fp));
}
//  printf("fp->_file %c\n",fp->_file);
  fclose(fp);
return 0;
}
