#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int j,a,b,c,i;
	cout<<"Enter the first number \n";
	cin>>a;
	cout<<"Enter the second number \n";
	cin>>b;
	cout<<"\nThe Prime numbers are \n";
	for(j=a;j<=b;j++)
	{
		c=0;
		for(i=2;i<j;i++)
		{
        	if (j % i == 0)
        		{
            	c++;
       			}
    	}
    	if (c == 0)
    	{
        	cout <<j<<" ";
    	}

    	else
    	{
        	cout <<"";
    	}
	}
	return 0;
	
}
