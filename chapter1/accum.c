#include<stdio.h>
#include<stdlib.h>

main()
{
    int i = 1,sum = 0;
    while(i <= 100) sum += i++;
    printf("sum is %d\n",sum);
    return EXIT_SUCCESS;
}
