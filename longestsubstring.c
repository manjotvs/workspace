/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring( char* s )
{
    char n;
    char sl[2];
    int i,j,temp,flag = 1;
    n = strlen(s);
    printf("Len: %d",n);
    if(n<1)
    {
        return 0;
    }
    char substring[n],oldsubstring[n];
    substring[0] = s[0];
    substring[1] = '\0';
    
    for(i=0,j=i+1;j<n;i++,j++)
    {
        while(i!=j && i < n)
        {
            if(s[i] == s[j])
            {
                i = j++;
                if(strlen(substring) > strlen(oldsubstring))
                {
                    strcpy(oldsubstring,substring);
                }
                substring[0] = '\0';
            }
            else if(( j - i ) > 1)
            {
                if(flag)
                {
                    flag = 0;
                    temp = i;
                }
                i++;
            }
            else
            {
                if(substring[0]== '\0')
                {
                    sl[0] = s[i];
                    sl[1] = '\0';
                    strcat(substring,sl);
                }
                sl[0] = s[j];
                sl[1] = '\0';
                strcat(substring,sl);
                j++;
                if(!flag)
                {
                    i = temp;
                    flag = 1;
                }
            }
        }
    }
    printf("Substring: ");
    if(oldsubstring[0]!='\0')
    {
        puts(oldsubstring);
        return strlen(oldsubstring);
    }
    else
    {
        puts(substring);
        return strlen(substring);
    }
}
int main()
{
    char string[]="pwwkewkll";
    printf("Longest substring length: %d\n",lengthOfLongestSubstring(string));
    return 0;
}