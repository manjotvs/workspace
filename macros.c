/* Online C Compiler and Editor */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Understand how preprocessor works

#define CONDITION(C) \
printf("Preprocessor %d\n",C);


//    Create a macro (named C_TO_F) of type independent to convert from degrees Celsius to Fahrenheit.
//    Macro should work for integer or floating point types
//    Note: degF = degC * (9/5) + 32
// Note both macros for int and float types
#define C_TO_F1(degC) (degC * 9/5 + 32)


#define C_TO_F2(degC) ({\
                    typeof(degC) a = degC*9.0;\
                    a /=5;\
                    a + 32;\
                    })

//#define min_num(a,b) (a>b?a:b) // This works if there is no other function is passed to a or b.
#define min_num(a,b) ({\
        typeof(a) _a = (a); \
        typeof(b) _b = (b); \
        _a>_b?_a:_b; \
        }) // This works everytime even it is type independent
int rand_num()
{
    int a = (rand()%100);
    printf("%s:%d\n",__func__,a);
    return a;
}

void flip_hi_lo(uint8_t* b)
{
    *b ^= 0x81;
}


#define x - -     - -5
#define sqr(x) ++x * x++
// #define sqr(x) ++x * ++x
// #define sqr(x) x++ * x++
// #define sqr(x) x++ * ++x
#define x 1+2



// Concatenation
//#define CAT(a,b) #a ## #b //illegal
#define CAT(a,b) a ## b
#define y "ABC""CDE" "deada" "dajnfka"
#define z "CDE\n"
#define string_concatenation_only(a,b) a b

// STRINGIFICATION
#define CAT1(a,b) #a#b
#define STR(A) #A
#define STR1(A) A // illegal

#define  preprocessor_works(x, y)  \
    printf(#x " and " #y " are great!\n")

//OVerride the line and file
#line 1 "HI"

int main()
{
    uint8_t a = 0xFF;
    flip_hi_lo(&a);
    printf("Flips Bits from 0x%02X to 0x%02X\n", 0xFF, a);

    CONDITION(2)
    int l = - - -  - -      9;
    printf("x= %d %d\n",x,l);
    int m = 5;
    printf("sqt: %d\n", sqr(m));
    int i;
    i = x * x * x;
    printf("%d\n",i);

    char DATE[15] = "Current Date";
    printf("%s\n", __DATE__ );
    printf("%s\n",__TIME__);
    {
        int t1 = C_TO_F1(21);
        float t2 = C_TO_F1(21.23);
        printf("%d %f\n",t1,t2);
    }
    {
        int t1 = C_TO_F2(21);
        float t2 = C_TO_F2(21.23);
        printf("%d %f\n",t1,t2);
    }
    int n1,n2,n3;
    n3 = min_num(rand_num(), rand_num());
    printf("%d %d %d\n",n1,n2,n3);

    // C concatenates adjacent strings: Example "abc" "def" will become "abcdef".
    // Stringification
    {
        preprocessor_works("khhkjbnubkj",9);
        printf("%s", "anc" "deg\n");
        printf("%s\n",STR(afnfla.0901i3 9i091jf a-13@#%&^*));
        printf("%s\n", CAT1(bdfad,adfadf));
       // printf("%s \n", STR1(abc)); // illegal
    }
    printf("Concatenation\n");
    // Concatenation
    {

        printf("%s",string_concatenation_only(y,z));
        printf("%d\n", CAT(4433,89));
       // printf("%s", CAT("abc","deg")); //illegal
    }
    // Overiding the line and file name
    {
        printf("%d %s\n", __LINE__, __FILE__);
    }
}