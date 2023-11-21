class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type S: str
        :rtype: List[int]
        """
        i = 0
        j = 0
        k = 0
        flag = True
        #print(len(s2))
        if(len(s3) != (len(s1) + len(s2))):
            return False

        while(i < len(s3)):
            if(flag):

                #print(s3[i], j, k)
                if(j < len(s1) and s3[i] == s1[j]):
                    j+=1
                elif((k < len(s2)) and (s3[i] == s2[k])):
                    print("1. switch to s2")
                    flag = False
                elif((k < len(s2)) and (i > 0) and (s3[i-1] == s2[k])):
                    print("2. switch to s2",s3[i-1], s2[k])
                    flag = False
                    i-=1
                    j-=1
                else:
                    return False
            if(flag == False):

                #print(s3[i], j, k)
                if(k < len(s2) and s3[i] == s2[k]):
                    k+=1
                elif((j < len(s1)) and (s3[i] == s1[j])):
                    print("switch to s1")
                    flag = True
                    continue

                elif((j < len(s1)) and (i > 0) and  (s3[i-1] == s1[j]) ):
                    print("switch to s1")
                    flag = True
                    i-=1
                    k-=1
                    continue
                else:
                    return False
            i+=1
        return True
        
# s="6[a]3[b]"
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
# s1 = "aabcc"
# s2 = "dbbca"
# s3 = "aadbbbaccc"
# s1 = "aa"
# s2 = "ab"
# s3 = "aaba"
# s1 = "db"
# s2 ="b"
# s3 = "cbb"
s1="aabd"
s2 = "abdc"
s3 ="aabdabcd"
soln = Solution()
print(soln.isInterleave(s1, s2, s3))