#include<iostream>
#include<iomanip>
#define MAX 20
#define TEMP 0
#define PERM 1
#define infinity 9999
using namespace std;
struct node
{
	int predecessor;
	int dist; 
	int status;
};

int adj[MAX][MAX];
int n;

void create_graph()
{
	int i,max_edges,origin,destin,wt;

	cout<<"Enter number of vertices : ";
	cin>>n;
	
	max_edges=(n*(n-1))/2;

	for(i=1;i<=max_edges;i++)
	{
		cout<<"Enter edge (0 0 to quit) : ";
		cin>>origin>>destin;
		if((origin==0) && (destin==0))
			break;
		cout<<"Enter Heuristic value for this edge : ";
		cin>>wt;
		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			cout<<"Invalid edge! "<<endl;
			i--;
		}
		else
			adj[origin][destin]=wt;
			adj[destin][origin]=wt;
	}
}

void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<setw(4)<<adj[i][j];
		}
		cout<<endl;
		
	}

}

int findpath(int s,int d,int path[MAX],int *sdist)
{
	struct node state[MAX];
	int i,min,count=0,current,newdist,u,v;
	*sdist=0;

	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = infinity;
		state[i].status = TEMP;
	}

	
	state[s].predecessor=0;
	state[s].dist = 0;
	state[s].status = PERM;


	current=s;
	while(current!=d)
	{
		for(i=1;i<=n;i++)
		{
		
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				newdist=state[current].dist + adj[current][i];
			
				if( newdist < state[i].dist )
				{
					state[i].predecessor = current;
					state[i].dist = newdist;
				}
			}
		}
		
		min=infinity;
		current=0;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist < min)
			{
				min = state[i].dist;
				current=i;
			}
		}

		if(current==0) 
			return 0;
		state[current].status=PERM;
	}


	while( current!=0 )
	{
		count++;
		path[count]=current;
		current=state[current].predecessor;
	}

	for(i=count;i>1;i--)
	{
		u=path[i];
		v=path[i-1];
		*sdist+= adj[u][v];
	}
	return (count);
}

int main()
{
	int i,j;
	int source,dest;
	int path[MAX];
	int shortdist,count;

	create_graph();
	cout<<"The adjacency matrix is :"<<endl;
	display();

	while(1)
	{
		cout<<"Enter the source  node(0 to quit) :";
		cin>>source;
		cout<<"Enter the destination  node(0 to quit) :";
		cin>>dest;

		if(source==0 || dest==0)
           {
             return 1;
          }
		count = findpath(source,dest,path,&shortdist);
		if(shortdist!=0)
		{
			
			cout<<"The distance is: "<<shortdist<<endl;
			cout<<"The greedy Bfs traversal follows the following  path is: ";
			for(i=count;i>1;i--)
			{
				cout<<path[i]<<"->";
			}
			cout<<path[i]<<endl;;
		
		}
		else
			{
				cout<<"There is no path from source to destination "<<endl;
			}
	}
}
