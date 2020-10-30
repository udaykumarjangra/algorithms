#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int board[20],count;

int main()
{
         int n,i,j;
         void queen(int row,int n);

         cout <<" - Implementaion of N-Queens Problem Using Backtracking -";
         cout <<"\n\nEnter number of Queens: ";
         cin >> n;
         queen(1,n);
         return 0;
}

//function for printing the solution
void print(int n)
{
         int i,j;
         printf("\n Solution %d:\n\n",++count);

         for(i=1;i<=n;++i)
          printf("\t%d",i);

         for(i=1;i<=n;++i)
         {
          printf("\n\n %d",i);
          for(j=1;j<=n;++j) //for nxn board
          {
           if(board[i]==j)
            printf("\tQ"); //queen at i,j position
           else
            printf("\t-"); //empty slot
          }
         }

         cout << "\n\n------------------------------------------------------------------------------------------------------------------\n";
         cout << "------------------------------------------------------------------------------------------------------------------\n\n";
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
         int i;

         for(i=1;i<=row-1;++i)
         {
          //checking column and digonal conflicts
          if(board[i]==column)
                {
                     //cout << " Queen can't be placed at column = " << column << endl;
                     return 0;
                }

          else
           if(abs(board[i]-column)==abs(i-row))
               {
                     //cout << " Queen can't be placed at column = " << column << endl;
                     return 0;
               }

         }

         return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)
{
         int column;

         for(column=1;column<=n;++column)
         {
          if(place(row,column))
          {
                //cout << "\nQUEEN "<<row<<" ---";
                //cout << "\nWe will try to place the queen in row = "<< row <<" and column = "<<column;
                board[row]=column;
                //cout << "\nQueen("<<row<<") can be placed at column = " << column << endl; //no conflicts so place queen
                //cout << " \n------------------------------------------------------------------------------------------------------------------\n";

           if(row==n) //dead end
            print(n); //printing the board configuration

                       else
                       {//try queen with next position
                        //cout << "Now checking the column where the next queen can be placed in row = "<<row+1<<endl;
                        queen(row+1,n);
                       }
          }
         }
}
