#include<iostream>
#include<list>

using namespace std;


class Graph 
{ 
    int Vertices;   
  
     
    list<int> *adj;    
public: 
    Graph(int Vertices);   
  
    
    void addEdge(int v, int u);  
  
    
    void BFS(int s);   
}; 
  
Graph::Graph(int Vertices) 
{ 
    this->Vertices = Vertices; 
    adj = new list<int>[Vertices]; 
} 
  
void Graph::addEdge(int v, int u) 
{ 
    adj[v].push_back(u); 
} 
  
void Graph::BFS(int s) 
{ 
    
    bool *visited = new bool[Vertices]; 
    for(int i = 0; i < Vertices; i++) 
        visited[i] = false; 
  
    
    list<int> queue; 
  
   
    visited[s] = true; 
    queue.push_back(s); 
  
    
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
      
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  

int main() 
{ 
    
    Graph a(5); 
    a.addEdge(0, 1); 
    a.addEdge(0, 2); 
    a.addEdge(1, 2); 
    a.addEdge(2, 0); 
    a.addEdge(2, 3); 
    a.addEdge(3, 3); 
    a.addEdge(1, 4);
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n"; 
    a.BFS(0); 
  
    return 0; 
}




