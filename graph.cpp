#include<iostream>

using namespace std;

int main()
{
	int i,j;
	
	int cost; //weight of edge
	
	//defining number of vertices
    int n;
    cout<<"Enter the number of vertices you want in the graph ";
    cin>>n;
    
    //declaring an array that contain all the vertices
    int vertices[n];
    for(i=0;i<n;i++)
    vertices[i]=i;
    
    
    char cont;
    int matrix[n][n];  //declaring adjacency matrix
    
    //making the user to enter weight of the edges
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(i!=j)
    		{
    			cout<<"Does there exist any edge directed from vertix "<<vertices[i]<<" to "<<vertices[j]<<" Y/N?"<<endl;
    		    cin>>cont;
    		
    		    if(cont=='Y'||cont=='y')
    		    {
    			cout<<"Enter the weight of the edge ";
    			cin>>cost;
    			matrix[i][j]=cost;
			    }
			    
			    else
			    {
			    	matrix[i][j]=1000;
			    	//here 1000 represents infinity i.e. the edges are not connected
				}	
	    	}
	    	
	    	else
	    	{
	    		matrix[i][j]=0;
			}
		}
	}
	
	
	//printing the adjacency matrix
	cout<<endl<<"The adjacency matrix for the graph is: "<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<matrix[i][j];
		}
	}
    
    cout<<endl<<endl<<"Note: The value 1000 represents that there might be no edge between the"<<endl
	                <<"vertices or distance between them is infinity"<<endl;
    
    //asking the user to enter the source node
    int source;
    cout<<"Enter the source node ";
    cin>>source;
    
    //Declaring the array that will contain the traversed nodes
    int S[n];
    
    //declaring array distance which contains the minimum distance of each vertex from the source node
    int distance[n];
    for(i=0;i<n;i++)
    {
    	if(i!=source)
    	distance[i]=1000;
    	
    	distance[source]=0;	
	}
	
	//declaring the array which contains the predecessors of each vertex in shortest path
	int pred[n];
	for(i=0;i<n;i++)
	{
		if(i!=source)
		pred[i]=-1;
		
		pred[source]=source;
	}
	
	//declaring an another array Q which contains the vertices' distances yet to be traversed
	int Q[n];
	for(i=0;i<n;i++)
	Q[i]=distance[i];
    
    int k=0;
    int pos;
    S[n-1]=n;
    
    int num=n;
    while(S[n-1]==n)  //Terminating condition....the loop continues till all the nodes are traversed
    {
    	int min=1000;
    	
    	for(i=0;i<num;i++)  // extracting the minimum value out of Q and the correspoinding vertex
    	{
    		if(Q[i]<min)
    		{
    			min=Q[i];
    			pos=i;
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(matrix[pos][i]!=1000)
			{
				if(distance[i]>distance[pos]+matrix[pos][i])
				{
					distance[i]=distance[pos]+matrix[pos][i];
					Q[i]=distance[i];
					pred[i]=pos;
				}
			}
		}
		
		S[k]=pos;
		k++;
		
		num=num-1;
		
		//Deleting the traversed node's distance
		for(i=pos;i<num;i++)
		{
			Q[i]=Q[i+1];
		}
	}
	
	cout<<"Hence the solution found using DIJKSTRA Algorithm is :"<<endl<<"Vertices\tMin. Distance\tPredecessor"<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<vertices[i]<<"\t\t"<<distance[i]<<"\t\t"<<pred[i]<<endl;
	}
	
	
    return 0;
}
