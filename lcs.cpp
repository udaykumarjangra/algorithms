//Longest Common Subsequence

#include<iostream>

using namespace std;

int print_lcs(char dir[][100], int x, int y, char *ch)
{
	if(x==0 && y==0)
	return 0;
	
	else
	{
		if(dir[x][y]=='r')
		{
			print_lcs(dir,x-1,y-1,ch);
			cout<<ch[x];
		}
		
		else if(dir[x][y]='t')
		{
			print_lcs(dir,x-1,y,ch);
		}
		
		else
		print_lcs(dir,x,y-1,ch);
	}
	
}

int main()
{
	int i,j,p,q;
	
	int m; //length of first sequence
	int n; // lengtg of second sequence
	
	cout<<"Enter the length of first sequence: ";
	cin>>m;
	cout<<"Enter the length of second sequence: ";
	cin>>n;
	
	p+m+1;
	q=n+1;
	
	char seq1[m]; //first sequence
	char seq2[n]; //second sequence
	
	cout<<"Enter the subsequences: "<<endl;
	cout<<"First sequence - ";
	for(i=0;i<m;i++)
	cin>>seq1[i];
	cout<<"Second sequence - ";
	for(i=0;i<n;i++)
	cin>>seq2[i];
	
	int length[p][q]; //length matrix
	char direction[p][100]; //direction matrix 
 
	for(i=1;i<p;i++)
	length[i][0]=0;
	
	for(j=0;j<q;j++)
	length[0][j]=0;
	
	//Algorithm to find the entries to length and direction matrix
	for(i=1;i<p;i++)
	{
		for(j=1;j<q;j++)
		{
			if(seq1[i-1]==seq2[j-1])
			{
				length[i][j]=length[i-1][j-1]+1;
				direction[i][j]='r';  //r points to the length[i][j] value			
			}
			
			else if(length[i-1][j]>=length[i][j-1])
			{
				length[i][j]=length[i-1][j];
				direction[i][j]='t'; //t ponts to the length[i-1][j] value
			}
			
			else
			{
				length[i][j]=length[i][j-1];
				direction[i][j]='l';  //l points to the length[i][j-1] value
			}
		}
	}
	
	cout<<length[1][2];
	
	cout<<"The length matrix is :"<<endl;
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				cout<<length[i][j];
				cout<<"\t";
			}
			
			cout<<endl;
		}
		
	cout<<"The direction matrix is: "<<endl;
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				cout<<direction[i][j];
				cout<<"\t";
			}
			
			cout<<endl;
		}
		
print_lcs(direction,p,q,seq1);
	

	return 0;
}
