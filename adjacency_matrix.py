class graph:
	def __init__(self, num):
		self.num_vertices = num
		self.matrix = [[-1 for x in range(num) ] for y in range(num)]
		self.vertices_list = [0] * num
		self.vertices = {}

	def add_vertice(self, vtx, id):
		self.vertices[id] = vtx
		self.vertices_list[vtx] = id

	def add_edge(self, frm, to, val):
		frm = self.vertices[frm]
		to = self.vertices[to]
		self.matrix[frm][to] = val
		self.matrix[to][frm] = val

	def get_edges(self):
		edges = []
		for i in range(self.num_vertices):
			for j in range(self.num_vertices):
				if(self.matrix[i][j] != -1):
					edges.append((self.vertices_list[i], self.vertices_list[j], self.matrix[i][j]))
		return edges




gobj = graph(6)
gobj.add_vertice(0,'a')
gobj.add_vertice(1,'b')
gobj.add_vertice(2,'c')
gobj.add_vertice(3,'d')
gobj.add_vertice(4,'e')
gobj.add_vertice(5,'f')

gobj.add_edge('a','e',10)
gobj.add_edge('a','c',20)
gobj.add_edge('c','b',30)
gobj.add_edge('b','e',40)
gobj.add_edge('e','d',50)
gobj.add_edge('f','e',60)
print(gobj.num_vertices)
print(gobj.vertices)
print(gobj.matrix)
print(gobj.vertices_list)
print("Adjacency Matrix of Graph")
print(gobj.get_edges())

