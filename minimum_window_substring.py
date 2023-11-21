#! /bin/python
import sys
#Global Varaibles
INT_MAX = sys.maxsize

class Solution:
	def populate_table(self, pattern, table):
		# first populate all the unique characters in table
		#update the counter with the len of unique characters in pattern
		counter = len("".join(set(pattern)))
		for c in "".join(set(pattern)):
			table[c] = 0
		# Now update all the characters appearance in the tables
		for c in pattern:
			table[c] += 1
		return counter

	def minWindow(self, s: str, t: str) -> str:
		beg = 0
		end = 0
		sub_len = INT_MAX
		table = {}
		counter = self.populate_table(t, table)
		msg_size = len(s)
		subString = ""

		while(end < msg_size):
			if s[end] in t:
				table[s[end]] -= 1
				if( table[s[end]] == 0 ):
					counter -=1
			while( counter == 0 ):
				if(( end - beg )< sub_len ):
					sub_len = end -beg
					subString = s[beg:end+1]
				#If counter is zero now slide the begining pointer
				if s[beg] in t:
					table[s[beg]] += 1
					if( table[s[beg]] > 0 ):
						counter +=1
				beg+=1
			end +=1
		return subString

	



message = "adobecodebanc"
pattern = "abc"
soln = Solution()
subString = soln.minWindow(message, pattern)

print(subString)