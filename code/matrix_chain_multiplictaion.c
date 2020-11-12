#include<iostream>
using namespace std;

int main()
{
	int no,q;
	cout<<"Enter no. of dimensions";
	cin>>no;
	int dim[no];
	cout<<"Enter "<<no<<"numbers";
	for(int i=0; i<no; i++)
	{
		cin>>dim[i];
	}
	int m[no][no];
	for(int i=1; i<no; i++)
	{
		m[i][i]=0;
	}
	for( int l=1; l<no; l++)
	{	cout<<"Size of sub problem "<<l<<endl;
		cout<<"Number of sub problems "<<no-l+1<<endl;
		if(l==1)
		{
			for(int i=0; i<no; i++)
			{
				cout<<"Number of qplication for chain "<<i<<"-"<<i<<" is 0"<<endl;
			}
		}
		else{
			for(int i=0; i<no-l+1; i++)
		{	
		    int j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i; k<j; k++)
			{
				q=m[i][k]+m[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
				
			}
			cout<<"Number of qplication for chain "<<i+1<<"-"<<j+1<<"is "<<q<<endl;
			if(q<m[i][j])
			{
				m[i][j]=q;
			}
		}
		}
	}
	cout<<"Number of qplication "<<m[1][no-1];
	return 0;
}
