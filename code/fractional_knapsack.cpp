#include<bits/stdc++.h>
using namespace std;
struct item
{
	int weight;
	int value;
};
bool c(struct item a, struct item b)
{
	float ratio1= (float)a.value/a.weight;
	float ratio2= (float)b.value/b.weight;
	return ratio1>ratio2;
}
int main()
{
	int w, no;
	cout<<"Enter Maximum Capacity of Knapsack\n";
	cin>>w;
	cout<<"Enter Number of items\n";
	cin>>no;
	struct item a[no];
	cout<<"Enter Value and Weight of "<<no<<" items \n";
	for(int i=0; i<no; i++)
	{
		cout<<"Value of item "<<i<<" ";
		cin>>a[i].value;
		cout<<"Weight of item "<<i<<" ";
		cin>>a[i].weight;
	}
	sort(a,a+no,c);
	float weight=0;
	float value=0;
	for ( int i=0 ; i<no ; i++)
	{
		if(weight + a[i].weight <= w)
		{
			weight+= a[i].weight;
			value+= a[i].value;
		}
		else
		{
			int remaining = w - weight;
			value+= a[i].value * (float)remaining/a[i].weight;
		}
	}
	cout<<endl<<"Max Value can be "<<value;
	return 0;
}
