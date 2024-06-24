#include <iostream>
using namespace std;
int main()
{
float i,j,n,k;
cout<<"Enter the number of lines \n";
cin>>n;
for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
			{
				cout<<" ";
			}
		for(k=1;k<=2*n-2*i+1;k++)
			{
				cout<<"*";
			}
		cout<<" \n";
}
return 0;
}
