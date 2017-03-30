#include<stdio.h>
#include<string.h>


int
main()
{
// shell exit 44 Channel number out of range
	printf("shell exit 44 %s\n",strerror(44));
printf("shell max exit 133 %s\n",strerror(133));
printf("shell  exit 134 %s\n",strerror(134));
	return 0;
}
