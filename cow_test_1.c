#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
intptr_t Mytop(uintptr_t vaddr) 
{
    FILE *pagemap;
    intptr_t paddr ;
    int offset = (vaddr / sysconf(_SC_PAGESIZE)) * sizeof(uint64_t);
    uint64_t e;
    if ((pagemap = fopen("/proc/8858/pagemap", "r"))) 
    {
        if (lseek(fileno(pagemap), offset, SEEK_SET) == offset) 
	{
            if (fread(&e, sizeof(uint64_t), 1, pagemap)) //uint64_t
	    {
        	if (e & (1ULL << 63)) 
		{ // page present ?
                    paddr = e & ((1ULL << 54) - 1); // pfn mask
		    //printf();
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
intptr_t Mytop2(uintptr_t vaddr) 
{
    FILE *pagemap;
    intptr_t paddr ;
    int offset = (vaddr / sysconf(_SC_PAGESIZE)) * sizeof(uint64_t);
    uint64_t e;
    if ((pagemap = fopen("/proc/8859/pagemap", "r"))) 
    {
        if (lseek(fileno(pagemap), offset, SEEK_SET) == offset) 
	{
            if (fread(&e, sizeof(uint64_t), 1, pagemap)) //uint64_t
	    {
        	if (e & (1ULL << 63)) 
		{ // page present ?
                    paddr = e & ((1ULL << 54) - 1); // pfn mask
		    //printf();
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
int main()
{
	printf("Physical Address:%u\n",Mytop( (uintptr_t)3213076264));
	printf("Physical Address:%u\n",Mytop2( (uintptr_t)3213076264));
}
