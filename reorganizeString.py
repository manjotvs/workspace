class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        N = len(S)
        print(N)
        A = []
        for c,x in sorted(((S.count(x),x) for x in set(S)), reverse =True):
            if(c > ((N+1)/2)):
                return ""
            A.extend(c*x)
        ans = [None] * N
        if(N%2 == 0):
            N = int(N/2)
        else:
            N = int(N/2)+1
        ans[::2], ans[1::2]= A[:N], A[N:]
       # ans[::2]= A[:N+1]
        #print(A[-1:])
        return("".join(ans))


S = "aab" 
#S = "aaab" 
# S = "aaaaaabbccccc"   
# S = "abbabbaaab"
#S = "vvvlo"
soln = Solution()
print(soln.reorganizeString(S))