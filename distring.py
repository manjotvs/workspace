class Solution(object):
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        i = 0
        j = len(S)
        k = 0
        l = [-1] * (j+1)
        while( k < len(S) ):
            if(S[k] == "I"):
                l[k] = i
                i+=1
            elif(S[k] == "D"):
                l[k] = j
                j-=1
            else:
                return []
            k+=1
        l[k] = i
        return l
# s="6[a]3[b]"
s="DDI"
soln = Solution()
print(soln.diStringMatch(s))