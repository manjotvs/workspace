class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        i = 0
        s = 0
        r = 1
        c = 0
        while(i < len(S)):
            w = widths[ord(S[i]) - ord('a')]
            if((s+w) > 100):
                r+=1
                s = 0
            else:
                s+=w
                i+=1
        #print(s,w)
        return([r,s])
        

        
        

widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
soln = Solution()
#soln.removeBackspaceCharacters(s2)
print(soln.numberOfLines(widths, S))