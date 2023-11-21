class Solution:
	def findJudge(self, N, trust):
		if( N == 1 ):
			return 1
		judge = -1
		graph =  [[ 0 for i in range(N)] for j in range(N)]
		for i,j in trust:
			graph[i-1][j-1] = 1
		for col in range(N):
			indegree = 0
			for row in range(N):
				if( graph[row][col] == 1 ):
					indegree+=1
					#print(indegree)
					if(indegree == (N-1)):
						judge = col+1
						for itr in range(N):
							if( graph[col][itr] == 1):
								indegree = 0
								judge = -1
								break
		return judge

# Runtime: 1888 ms, faster than 5.13% of Python3 online submissions for Find the Town Judge.
# Memory Usage: 24.7 MB, less than 10.00% of Python3 online submissions for Find the Town Judge.


if __name__ == "__main__":
	num = 2
	trust = [[1,2]]
	# Output: 2
	# num = 3
	# trust = [[1,3],[2,3],[3,1]]
	#output = -1
	# num = 3
	# trust = [[1,2],[2,3]]
	# #ouput -1
	# num = 1
	# trust = []
	# #output 1
	# num = 2
	# trust = [[1,2],[2,1]]
	#output -1
	soln = Solution()
	print(soln.findJudge(num, trust))