from collections import defaultdict

class Graph:
    def __init__(self, num):
        self.num_vertex = num
        self.graph = defaultdict(list)
        self.visited = [0]*num

    def addEdge(self, frm, to):
        self.graph[frm].append(to)

    def BFS(self, vertex):
        queue = []
        queue.append(vertex)
        self.visited[vertex] = 1

        while(queue):
            s = queue.pop(0)
            print(s, end= " ")
            for i in self.graph[s]:
                if(self.visited[i] == 0):
                    queue.append(i)
                    self.visited[i] = 1



  
# Driver code 
  
# Create a graph given in 
# the above diagram 
g = Graph(4) 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
print(g.graph)
  
print ("Following is Breadth First Traversal"
                  " (starting from vertex 2)") 
g.BFS(2) 
print()