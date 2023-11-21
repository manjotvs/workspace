class Solution(object):
    #Brute Force
    def longestPalindrome1(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = 0
        N = len(s)
        pStr = ""
        while( i < N):
            j = i
            while( j < N):
                #print(s[i:j])
                if(self.isPalindrome(s[i:j+1])):
                    #print("True")
                    if(len(pStr) < ((j+1)-i)):
                        pStr=s[i:j+1]
                        #print("pstr:",pStr)
                j+=1
            i+=1
        return pStr


    def isPalindrome(self, s):
        i = 0
        N = len(s)
        j = N -1
        flag = True
        while( i < j):
            if(s[i] != s[j]):
                flag = False
            i+=1
            j-=1
        return flag

    # Reverse the string and find the longest substring
    def longestPalindrome(self, s):
        revS = ""
        revS = s[::-1] 
        #print(revS)
        #Let common longest substring is s in both s & revS
        i = 0
        N = len(s)
        if(N ==0):
            return ""
        strP = s[0]
        while(i< N):
            j =  N-1
            if(len(strP) > (j-i)):
                return strP
            while(j > i):
                if(s[i:j+1] in revS):
                    if((j-i) >= len(strP)):
                        nstrP = s[i:j+1]
                        strRP = nstrP[::-1]
                        if(strRP == nstrP):
                            strP = nstrP
                j-=1
            i+=1
        
        return strP


S = "aabaa"
#S = "aaab" 
#S = "aaaaaabbccccc"  
#S = "cbbd" 
#S="af"
#S="aaabbbaaa"
#S="abbaddabba"
# S= "babad"
#S = "a"
#S = "babad"
#S = "abbabbaaab"
#S = "vvvlo"
S= "abraarba"
S ="ab"
S=""
S="ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
#S= "abacdfgdcaba"
soln = Solution()
print(soln.longestPalindrome(S))