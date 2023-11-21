/* Online C Compiler and Editor */
#include <stdio.h>
#include <stdint.h>
typedef struct datafields
{
    uint8_t b;
    uint8_t c;
    //uint16_t d;
}df_t;
typedef union data
{
    uint16_t a;

    df_t df_p;
} data_t;

union Test
{
    char ProdName[10];
    int iAmount;
};
int main()
{
    data_t dat;
    dat.a = 0x12ABCDEF;
    printf("0x%02X\n", dat.df_p.b);
    printf("0x%02X\n", dat.df_p.c);
    //printf("0x%02X\n", dat.df_p.d); 
    dat.df_p.b = 0x21;
    dat.df_p.c = 0x43; 
    printf("0x%02X\n", dat.a); 
    printf("Size of Union = %ld\n", sizeof(union Test));

    return 0;
}