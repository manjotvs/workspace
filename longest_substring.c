#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_repeating_char(char *s, int beg, int end)
{
	if(beg == end)
		return -1;
	while(beg < end)
	{
		if(s[beg] == s[end])
		{
			printf("beg: %d end: %d\n",beg,end);
			return beg;
		}
		beg++;
	}
	printf("end\n");
	return -1;
}


int lengthOfLongestSubstring(char *s){
    if(!strlen(s))
        return 0;
    int beg = 0;
    int end = 0;
    int ret = 0;
    int l = 0;
    while((s[end] != 0) && (beg <= end))
    {
    	ret = find_repeating_char(s, beg, end);
    	if(ret!=-1)
    	{
    		if(end-beg > l)
    		{
    			l = end -beg;
    		}
    		beg = ret +1;
    	}
    	end++;
    }
    if(end -beg > l)
    	l = end -beg;

    return(l);
}


int main()
{
	char str[] ="pwkeww";
	printf("Length of longest substring %d\n",lengthOfLongestSubstring(str) );
	return 0;
}