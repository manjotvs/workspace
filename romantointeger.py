d = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        if(s==""):
            return
        res = 0
        i = 0
        while(i+1 < len(s)):
            if(d[s[i]] < d[s[i+1]]):
                res -= d[s[i]]
            else:
                res += d[s[i]]
            i+=1

        res += d[s[i]]
        return res

        

soln = Solution()
s= "MCMXCIV"
print(soln.romanToInt(s))


