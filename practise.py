# class Solution(object):
#     def hammingWeight(self, n):
#         """
#         :type n: int
#         :rtype: int
#         """
        

# soln = Solution()
# s= 00000000000000000000000000001011
# print(s)
# print(soln.hammingWeight(s))

class Solution:
    def longestCommonPrefix(self, strs):
        if(len(strs)):
            l = 0
            for c in strs[0]:
                i = 1
                for i in range(len(strs)):
                    if c != strs[i][l:l+1]:
                        return strs[0][:l]
                l+=1
            return strs[0][:l]
        return ""

str1 = "bcda"
print(str1[1::1])
str1 = ["aa", "ab"]
soln = Solution()
print(soln.longestCommonPrefix(str1))