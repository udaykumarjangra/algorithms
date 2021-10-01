#include <bits/stdc++.h> 

using namespace std; 

struct myItem 
{
	int itemNo; 
	int profit;
	int weight;
	float ppw; 
}; 
bool cmp(struct myItem a, struct myItem b) 
{ 
	return a.ppw > b.ppw; 
} 

float fractionalKnapsack(int Capacity, struct myItem arr[], int n) 
{ 
	for(int i=0;i<n;i++)
	{
		arr[i].ppw = ((float)arr[i].profit / arr[i].weight);
	}
 
	sort(arr, arr + n, cmp); 

	cout<<"details of all items : \n";
	cout<<"itemNo\t"<<"Profit\t"<<"Weight\t"<<"PPW\t"<<endl;
	for (int i = 0; i < n; i++) 
	{ 
		cout <<arr[i].itemNo<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<((float)arr[i].ppw)<<endl; 
	}

	cout<<endl;

	float Max = 0.0; 
	int i=0; 

	while(Capacity > 0 && i<=n-1)
	{
	
		if(Capacity >= arr[i].weight)
		{
			Max = Max + (float)arr[i].profit;
			Capacity = Capacity - arr[i].weight;
		}
		else
		{
			Max += (Capacity * arr[i].ppw);
			Capacity = 0;
		}
		i++;
	}  

	return Max; 
} 

int main() 
{ 
	int C = 25;   //    Capacity of knapsack 
	myItem arr[] = { {1, 30, 10, 0}, {2, 20, 5, 0} , {3, 40, 15, 0}, {4, 36, 8, 0}}; 

	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"details of all items before sorting and without calculating PPW: \n";
	cout<<"itemNo\t"<<"Profit\t"<<"Weight\t"<<"PPW\t"<<endl;
	for (int i = 0; i < n; i++) 
	{ 
		cout <<arr[i].itemNo<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<((float)arr[i].ppw)<<endl; 
	} 

	cout<<endl;
	cout << "Maximum profit we can obtain = "<< fractionalKnapsack(C, arr, n);

	return 0; 
} 

