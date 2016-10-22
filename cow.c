#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
intptr_t Mytop(uintptr_t vaddr) 
{
    FILE *pagemap;
    intptr_t paddr = 0;
    int offset = (vaddr / sysconf(_SC_PAGESIZE)) * sizeof(uint64_t);
    uint64_t e;
    if ((pagemap = fopen("/proc/self/pagemap", "r"))) 
    {
        if (lseek(fileno(pagemap), offset, SEEK_SET) == offset) 
	{
            if (fread(&e, sizeof(uint64_t), 1, pagemap)) 
	    {
        	if (e & (1ULL << 63)) 
		{ // page present ?
                    paddr = e & ((1ULL << 54) - 1); // pfn mask
                    paddr = paddr * sysconf(_SC_PAGESIZE);
            		// add offset within page
            		paddr = paddr | (vaddr & (sysconf(_SC_PAGESIZE) - 1));
                }   
            }   
        }   
        fclose(pagemap);
    }   
    return paddr;
}  


void TestShow(void *x)
{
  printf("Virtual Address:%u  Physical Address:%u\n",x,Mytop((uintptr_t)x));
}

void main()
{
	int x = 0; 
	static int y = 0;
	pid_t pd = fork();
	if(pd>0)
	{
		sleep(2);
		printf("parent:local value ");
		TestShow(&x);
		printf("static value ");
		TestShow(&y);
		printf("x:%d  y:%d\n",x,y);
	}  
	else
	{
		//sleep(2);
		printf("child:local value ");
		TestShow(&x);
		printf("static value ");
		TestShow(&y);
		printf("x:%d  y:%d\n",x,y);
	}
	exit(0);
}
