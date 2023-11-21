#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reverseString(char* s, int sSize)
{
   int i = 0;
   int j = sSize -1;
   while(i < sSize/2)
   {
      s[i] = s[i] ^ s[j];
      s[j] = s[i] ^ s[j];
      s[i] = s[i] ^ s[j];
      i++;
      j--;
   }
}

char* reverseWords(char* s)
{
   if(s == NULL)
      return NULL;
   char *word = NULL;
   int len = strlen(s);
   int prev_len=0;
   char *revWords = (char*)calloc(len+1, sizeof(char));
   word = strtok(s, " ");
   while(word != NULL)
   {
      reverseString(word, strlen(word));
      strncpy(revWords + prev_len, word, strlen(word));
      prev_len += (strlen(word)+1);
      word = strtok(NULL, " ");
       if(word != NULL)
           revWords[prev_len-1] = ' ';
   }
   return revWords;
}

int main()
{
   //char arr[] = "Hello, I am Main Function!";
   char arr[] = "Let's take LeetCode contest";
  //char *arr = NULL;
   printf("Reverse Strings %s\n", reverseWords(arr) );
   return 0;
}