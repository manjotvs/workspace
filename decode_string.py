class Solution(object):
	def decodeStr(self, s, i):
		res=""
		while((i < len(s)) and ( s[i] != ']')):
			if(s[i].isdigit() is False):
				res+=s[i]
				i+=1
			else:
				num = 0
				print(s[i])
				while((i < len(s)) and s[i].isdigit()):
					num = (10 *num) +int(s[i])
					i+=1
				i+=1
				i, t = self.decodeStr(s, i)
				i+=1
				while(num > 0):
					num-=1
					res+=t
		return i,res


	def decodeString(self, s):
		i,s = self.decodeStr(s,0)
		return s

#s = "3[a]2[bc]"		
# s = "3[a6[g]]2[bc]4[d]"
# #s="2[abc]3[cd]ef3[zxs]"
#s="3[a2[c]]"
s= "2[abc4[de3[fg]]]ij"
# s = "2[abc]3[cd]ef"
# s="6[a]3[b]"
soln = Solution()
print(soln.decodeString(s))