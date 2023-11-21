class Solution(object):
    def firstUniqChar1(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        while(i < len(s)):
            print(s[i+1:], s[i], s[i] == s[i+1:])
            if(( s[i] not in s[i+1:]) and ( s[i] not in s[:i])):
                return i
            i+=1
        return -1
    
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        letters='abcdefghijklmnopqrstuvwxyz'
        index=[s.index(l) for l in letters if s.count(l) == 1]
        return min(index) if len(index) > 0 else -1
        

s = "leetcode"
s = "cc"
s = "x"

soln = Solution()
print(soln.firstUniqChar(s))