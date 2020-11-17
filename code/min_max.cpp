#include<bits/stdc++.h>
using namespace std;
void minmax(int arr[], int low, int high, int &min, int &max)
{
	int min1, max1;
	if(low==high)
	{
		max=min=arr[low];
		return;
	}
	else if(low==high-1)
	{
		if(arr[low]<arr[high])
		{
			min=arr[low];
			max=arr[high];
		}
		else if(arr[low]>arr[high])
		{
			max=arr[low];
			min=arr[high];
		}
		return;
	}
	int mid=(low+high)/2;
	minmax(arr,low,mid,min,max);
	min1=min; 
	max1=max;
	minmax(arr,mid+1,high,min,max);
	if(min1<min)
	{
		min=min1;
	}
	if(max1>max)
	{
		max=max1;
	}
	
}


int main()
{
	int no, min, max, low, high;
	cout<<"Enter number of elements to enter in array\n";
	cin>>no;
	int arr[no];
	cout<<"Enter "<<no<<" elements\n";
	for(int i=0; i<no; i++)
	{
		cin>>arr[i];
	}
	low=0;
	high=no-1;
	minmax(arr,low,high,min,max);
	cout<<"Minimum "<<min<<endl<<"Maximum "<<max;
}
