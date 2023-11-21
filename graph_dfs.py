from collections import defaultdict

class graph:
	def __init__(self):
		self.edges = defaultdict(list)

	def addEdge(self, u, v):
		self.edges[u].append(v)

	def DFSTraversal(self, vtx, visited):
		visited[vtx] = 1
		print(vtx)
		for i in self.edges[vtx]:
			print("i:",vtx, i)
			if(visited[i] == 0):
				self.DFSTraversal(i,visited)

	def dfs(self, vtx ):
		visited = [0] * (len(self.edges))
		self.DFSTraversal(vtx, visited)


# Driver code 
# Create a graph given in the above diagram 
g = graph() 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
print(g.edges)
  
print("Following is DFS from (starting from vertex 2)")
g.dfs(2) 