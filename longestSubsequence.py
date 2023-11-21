class Solution(object):
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m,n = len(text2), len(text1)
        lt = [[0]*(m+1) for i in range(n+1)]
        i = 1
        j = 1
        while(i <= n):
            j =1
            while(j <= m):
                if(text1[i-1] == text2[j-1]):
                    lt[i][j] = lt[i-1][j-1] + 1
                else:
                    lt[i][j] = max(lt[i-1][j],lt[i][j-1])
                j+=1
            i+=1
        print(lt)
        subStr = ""
        while((m>0) and (n>0)):
            print(lt[n][m])
            if(lt[n][m] !=  lt[n][m-1]):
                subStr += text2[m-1]
                m -=1
                n -=1
            else:
                m-=1
        print("sub:",subStr)
        return (lt[-1][-1])
        
        

soln = Solution()
s1 = "sea"
s2 = "eat"
# s1 = "delete"
# s2 = "leet"

# s1 = ""
# s2 = ""
# s1 = "ccaccjp"
# s2 = "fwosarcwge"
# s1 = "ceabd"
# s2 = "ace"
#print(ord('c'))
#print(soln.minimumDeleteSum(s1, s2))
s1 = "pmjghexybyrgzczy"
s2 = "hafcdqbgncrcbihkd"
#s1 = "ghbrgc"
#s2 = "hcbgcrcbh"

s1 = "mhunuzqrkzsnidwbun"
s2 = "szulspmhwpazoxijwbq"
# s1 = "mhuuzqzsiwbu"
# s2 = "szusmhwziwbq"
s1 = "papmretkborsrurgtina"
s2 = "nsnupotstmnkfcfavaxgl"
s2 = "abcdaf"
s1 = "acbcf"
print(soln.longestCommonSubsequence(s1, s2))