class _collections import defaultdict

class Graphs:
    def __init__(self):
        self.graphlist = defaultdict(list)
    def edgeaddition(sesf,n,v):
        self.graphlist[n].append(v)


    def DFSfun(self,v,visitnode):
        visitnode[v]=True
        print (v, end=' ')
        for i in self.graphlist[v]:
            if visitnode[i]==False:
                self.DFSfun(i,visitnode)
    def DFS(self,v):
        visit node=[false]*(max(self.graphlist)+1)
        self.DFSfun(v,visitnode)

g=Graph()
l = int(input("enter totle edges"))
for i in range(1):
    x=int(input("1"))
    y=int(input("2"))
    g.Edgeaddition(x,y)
    


s= int(input("enter the starting value"))
g.DFS(s)
