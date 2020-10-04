#include<bits/stdc++.h>
#include<stdlib.h>
#define mxn 10000
#define inf 0x3f3f3f3f



using namespace std;

vector< int > graph[mxn];
int start_node, goal_node, parent_node[mxn], heuristics[mxn];
bool visited[mxn];

int getParentNode(int node)
{
    return parent_node[node];
}

void path(int current_node)
{
    if(current_node == start_node)
    {
        printf("%d",current_node);
        return;
    }
    path(getParentNode(current_node));
    printf("->%d",current_node);
}

bool GBFS(int current_node)
{
    if(current_node == goal_node)
        return true;
    visited[current_node] = true;

    int child, best_child = -1, number_of_child = graph[current_node].size(), minimum = inf ;

    for(int i=0; i<number_of_child ;i++)
    {
        child = graph[current_node][i];
        if(!visited[child])
        {
            if(heuristics[child]<minimum)
            {
                best_child = child;
                minimum = heuristics[child];
            }
        }
    }
    if(best_child == -1)return false;

    parent_node[best_child] = current_node;
    return GBFS(best_child);
}

int main()
{
   // freopen("Greedy_Best_First_Search_Input.txt","r", stdin);

    int number_of_nodes, number_of_edges, edge_start, edge_end, n, h;
    printf("Enter the number of Nodes : ");
    scanf("%d",&number_of_nodes);
    printf("Enter the number of Edges : ");
    scanf("%d",&number_of_edges);
    printf("Enter the Edges : \n");

    for(int i=1; i<=number_of_edges; i++)
    {
        scanf("%d %d",&edge_start ,&edge_end);
        graph[edge_start].push_back(edge_end);
        graph[edge_end].push_back(edge_start);
    }

    printf("\nEnter start node : ");
    scanf("%d",&start_node);
    printf("Enter goal node : ");
    scanf("%d",&goal_node);
    printf("Enter the node then the heuristics for the node : \n");
    for(int i=1; i<=number_of_nodes; i++)
    {
        scanf("%d %d",&n ,&h);
        heuristics[n] = h;
    }

    printf("\nUsing Greedy best first Search");
    if(GBFS(start_node))
    {
        printf("\npath from start to goal node : ");
        path(goal_node);
        printf("\n");
    }
    else
    {
        printf("\nThere is no path from start to goal node.\n");
    }
    return 0;
}
