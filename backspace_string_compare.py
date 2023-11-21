class Solution(object):
    def removeBackspaceCharacters(self, s):
        while(s.find("#") >= 0):
            i = s.index("#")
            if(i > 0):
                s = s[:i-1] + s[i+1:]
            else:
                s = s[i+1:]
        print(s)
        return s
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        return( self.removeBackspaceCharacters(S) == self.removeBackspaceCharacters(T))

        
        

s1 = "a#b#acca"
s2 = "a#b#b#acca"
s1 = "a##c"
s2 = "#a#c"
s1 = "ab##"
s2 = "b#c#"
soln = Solution()
#soln.removeBackspaceCharacters(s2)
print(soln.backspaceCompare(s1, s2))