#include<unistd.h>
#include<stdio.h>

/*
@brief: 判断文件是否存在
@param: file_path,文件名称，包含路径

@return: 文件路径为空或者不存在文件返回-1，否则存在返回0

*/
//int access(const char* pathname,int mode);


int is_file_exist(const char* file_path)
{
	if(file_path == NULL)
		return -1;
	if(access(file_path,F_OK) == 0)
		return 0;
	return -1;
}


int 
main()
{
	int ret = -2;

	if((ret = is_file_exist("file_exist.c")) == -1)
		printf("file is not exist or file_path is wrong\n");
	else
		printf("file is exist!\n");
	if((ret = is_file_exist("ssfile_exist.c")) == -1)
		printf("ssfile_exist.c is not exist or file_path is wrong\n");
	else
		printf("ssfile_exist.c is exist!\n");
	return 0;
}
