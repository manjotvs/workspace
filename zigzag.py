class Solution:
	def convert(self, s: str, numRows: int) -> str:
		if(numRows == 1):
			return s
		updown = 0  # 1 -> up, 0-> down
		zigZag = [""] * numRows
		i=-1
		for c in s:
			if( i == (numRows -1)):
				updown = 1
			elif( i == 0):
				updown = 0

			if(updown):
				i-=1
			else:
				i+=1
			zigZag[i] +=(c)
		s=""
		for itr in zigZag:
			s+= itr
		return s


s = "PAYPALISHIRING" 
numRows = 3
#Output: "PAHNAPLSIIGYIR"
s = "PAYPALISHIRING"
numRows = 4
#Output: "PINALSIGYAHRPI"
s = "P"
numRows = 1
#Output: "PINALSIGYAHRPI"
s= "ABC"
numRows = 1
soln = Solution()
print(soln.convert(s, numRows))