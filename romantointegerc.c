#include <stdio.h>
#include <string.h>

int lookuptable( char c)
{
    switch(c)
    {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
    return 0;
}

int romanToInt(char * s)
{
    int i = 0;
    int res = 0;
    if(*s == '\0')
        return 0;
    while( i+1 < strlen(s))
    {
        if(lookuptable(s[i]) < lookuptable(s[i+1]))
        {
            res -= lookuptable(s[i]);
        }
        else
        {
            res += lookuptable(s[i]);
        }
        i++;
    }
    res += lookuptable(s[i]);
    return res;
}

int main()
{
    char *s = "MCMXCIV";
    printf("%d\n", romanToInt(s));

}