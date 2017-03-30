#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>

/*
@brief: 判断目录是否存在
@param: dir_path,目录名称，包含路径

@return: 目录路径为空或者不存在目录返回-1，否则存在返回0

*/

int is_dir_exist(const char* dir_path)
{
	if(dir_path == NULL)
		return -1;
	if(opendir(dir_path) == NULL) 
		return -1;
	closedir((DIR *)dir_path); // balance
	return 0;
}


int 
main()
{
	int ret = -2;

	char *home = "HOME";

	printf("$HOME is %s\n",getenv(home));

	if((ret = is_dir_exist(getenv(home))) == -1)
		printf("dir is not exist or dir_path is wrong\n");
	else
		printf("dir is exist!\n");
	if((ret = is_dir_exist("ssdir_exist.c")) == -1)
		printf("ssdir_exist.c is not exist or dir_path is wrong\n");
	else
		printf("ssdir_exist.c is exist!\n");
	return 0;
}
