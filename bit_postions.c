#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t setBitNumber(uint32_t n) 
{ 
    // Below steps set bits after 
    // MSB (including MSB) 

    // Suppose n is 273 (binary 
    // is 100010001). It does following 
    // 100010001 | 010001000 = 110011001 
    n |= n >> 1; 

    // This makes sure 4 bits 
    // (From MSB and including MSB) 
    // are set. It does following 
    // 110011001 | 001100110 = 111111111 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16;

    // Increment n by 1 so that 
    // there is only one set bit 
    // which is just before original 
    // MSB. n now becomes 1000000000 
    n = n + 1; 

    // Return original MSB after shifting. 
    // n now becomes 100000000 
    return (n >> 1); 
} 

void find_bit_pos(uint32_t n)
{
    uint32_t pos;
    while(n)
    {
        pos = setBitNumber(n);
        printf("Pos: %d\n",(int)(log(pos)/log(2)) );
        n = n & (~pos);
        printf("N: %d\n",n );
    }
}



// Driver code 
int main() 
{ 
    uint32_t n = 0xF0; 
    find_bit_pos(n); 
    return 0; 
} 