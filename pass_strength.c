#include <stdio.h>

void calculate_weight(char *str, int weight_a)
{
	int strength = 0;
	while(*str != 0)
	{
		strength += (((*str++ - 'a') + weight_a) % 26);
	}
	printf("strength: %d\n", strength );
}

int main()
{
	char pass[] = "aaaaa";
	int weight_a = 1;
	calculate_weight(pass, weight_a);
	return 0;
}

class Solution:

    """
    @param S: a string
    @param T: a string
    @return: the minimum substring of S
    """
    def minWindow(self, S, T):
        # Write your code here
        i = 0
        j = 0
        k = 0
        subSeq = ""
        l = len(S)+1
        while(i < len(S)):
            if(S[i] == T[j]):
                j+=1
            if( j >= len(T)):
                end = k = i
                
                while(j > 0):
                    if(S[k] == T[j-1]):
                        j-=1
                    k-=1
                if(l > ((end - k))):
                    subSeq = S[k+1: end+1]
            i+=1
        return subSeq
