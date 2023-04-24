#include<iostream>
#define N 10
using namespace std;
long long int solutions=0;
void printSolution(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(i=row,j=col;j>=0 && i<N;i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}
bool solveNQUtil(int board[N][N],int col)
{
    if(col==N)
    {
        solutions++;
        if(solutions==2)
        {
            printSolution(board);
        }
        
        return true;
    }
    bool res=false;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            res=solveNQUtil(board,col+1)||res;
            board[i][col]=0;
        }
        
    }
    return res;
}
void solveNQ()
{
    int board[N][N]={{0}};
    if(solveNQUtil(board,0)==false)
    {
        cout<<"Solution does not exist";
        return;
    }
    return ;
}
int main()
{
    solveNQ();
    cout<<endl;
    cout<<"Total Number of Solutions:"<<solutions;
    return 0;
}
