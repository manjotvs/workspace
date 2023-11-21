class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        subStr = ""
        beg= 0
        l = 0
        i = 0
        total_iter=0
        while(i < len(s)):
            print(s[i:])
            total_iter+=1
            if(s[i] not in subStr):
                subStr += s[i]
                i+=1
                #print(subStr)
            else:
                beg+=1
                i=beg
                if(l < len(subStr)):
                    l = len(subStr)
                subStr = ""
        if(l < len(subStr)):
            return len(subStr)
        else:
            return l
    def lengthOfLongestSubstring1(self, s: str) -> int:
        substr = ""
        temp = ""
        
        for c in s:
            print(s)
            if c not in temp:
                temp = temp + c
            else:
                if(len(temp) > len(substr)):
                    substr = temp
                while c in temp:
                    temp = temp[1:]
                temp += c
      
        if(len(temp) > len(substr)):
            substrlen = len(temp)
        else:
            substrlen = len(substr)
        return substrlen


str1 = "asjrgapa" #6
str1 = "abacwd" #5
str1 = "pwwkew" #3
#str1 = "aaaaaa" #3

soln = Solution()
print(soln.lengthOfLongestSubstring(str1))



