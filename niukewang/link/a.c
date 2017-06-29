#include<stdio.h>


extern void a(char* );

int
main()
{
	static char string[]= "Hello World\n";

	a(string);
	return 0;
}



