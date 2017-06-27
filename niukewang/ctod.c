#include <stdio.h>
#include <stdlib.h>


#define ctod(x) ((x) - '0')

int
main()
{
 	char x;
	scanf("%c",&x);
	printf("%d\n",ctod(x));
	return 0;
}
