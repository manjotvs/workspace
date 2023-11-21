#include <stdio.h>
#include <stdint.h>

void register_read(void* reg, void *result)
{
    uint32_t *p1 = (uint32_t*)reg;
    uint32_t *p2 = (uint32_t*)result;
    *p2++ = *p1++;
    *p2 = (*p1)+1;
}

int main()
{
    uint64_t reg=0xAAAAAAAAFFFFFFFF,result;
    
    
    register_read(&reg, &result);
    printf("0x%lX\n",result);
}
