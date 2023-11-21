class Node:
    def __init__(self, data):
        self.val = data
        self.next = None

class Solution:
	def findJudge(self, N, trust):
		if( N == 1 ):
			return 1
		judge = -1
		graph = [None] *( N+1)
		inorder = [0] * (N+1)
		for i,j in trust:
			n = Node(j)
			n.next = graph[i]
			graph[i] = (n)

		for i in range(N):
			node = graph[i+1]
			while node != None:
				inorder[node.val]+=1
				node = node.next
		for i in range(N+1):
			if(inorder[i] == (N-1)):
				if(graph[i] == None):
					judge = i
					break
			else:
				judge = -1

		return judge

# Runtime: 960 ms, faster than 8.67% of Python3 online submissions for Find the Town Judge.
# Memory Usage: 18.7 MB, less than 10.00% of Python3 online submissions for Find the Town Judge.

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
	num = 1
	trust = []
	# #output 1
	# num = 2
	# trust = [[1,2],[2,1]]
	#output -1
	num = 4
	trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
	#output 6
	num = 3
	trust = [[1,3],[2,3],[3,1]]
	#output -1
	num = 4
	trust = [[3,2],[4,1],[3,1],[2,1],[2,3],[4,3],[4,2],[3,4]]
	#output 1
	soln = Solution()
	print(soln.findJudge(num, trust))