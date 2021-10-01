#include <vector>
#include <list>
#include<iostream>
 
using namespace std;
 
void breadthFirstSearch(vector<list<int> > adjacencyList, int start,int vertices)
{
    list<int>::iterator itr;
 
    
    bool *visit= new bool[vertices];
	for(int i=0;i<vertices;i++)
	{
		visit[i]=false;
	}
 
    list<int> VertexQueue;   
 
    VertexQueue.push_back(start);
    visit[start]=true;
 
    while (!VertexQueue.empty())    
    {
        int newVertex = VertexQueue.front();
       
 
        itr = adjacencyList[newVertex].begin();
        
 
        while (itr != adjacencyList[newVertex].end())
		 {
            if (!visit[*itr]) 
			{      
			   visit[*itr]=true;           
                VertexQueue.push_back(*itr);  
                cout<<*itr<<" ";
            }
            ++itr;
        }
 
        VertexQueue.pop_front();    
    }
}
 
int main()
{
    int vertices, edges, v1, v2, weight;
 
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
 
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
 
   
    vector< list<int> > adjacencyList(vertices );
 
    printf("Enter the Edges V1 -> V2\n");
 
    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);
 
       
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }
 
    printf("\nThe Adjacency List-\n");
    
    for (int i = 0; i < adjacencyList.size(); ++i)
	 {
        printf("adjacencyList[%d] ", i);
 
        list<int>::iterator itr = adjacencyList[i].begin();
 
        while (itr != adjacencyList[i].end()) {
            printf(" -> %d", *itr);
            ++itr;
        }
        printf("\n");
    }
 
   
    printf("\nEnter the Starting Vertex -\n");
    scanf("%d", &v1);
    cout<<"The order is as follows :"<<endl;
    cout<<"0 ";
    breadthFirstSearch(adjacencyList,  v1,edges);
    
   
 
    return 0;
}
