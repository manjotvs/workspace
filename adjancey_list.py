class node:
    def __init__(self, data):
        self.vertex = data
        self.next = None

class graph:
    def __init__(self, num):
        self.num_vertices = num
        self.vertices_list = [None] * num

    def add_edge(self, frm, to):
        n = node(to)
        n.next = self.vertices_list[frm]
        self.vertices_list[frm] = n

        n = node(frm)
        n.next = self.vertices_list[to]
        self.vertices_list[to] = n

    def get_edges(self):
        edges = []
        for i in range(self.num_vertices):
            node = self.vertices_list[i]
            print("Edges for vertex {}\nhead".format(i), end="")
            while(node != None):
                print("-->",node.vertex, end="")
                node = node.next
            print("")




if __name__ == "__main__":
    gobj = graph(5) 
    gobj.add_edge(0, 1) 
    gobj.add_edge(0, 4) 
    gobj.add_edge(1, 2) 
    gobj.add_edge(1, 3) 
    gobj.add_edge(1, 4) 
    gobj.add_edge(2, 3) 
    gobj.add_edge(3, 4) 
  
    gobj.get_edges() 

