#include<iostream>
#include<stdlib.h>
using namespace std;
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
static int comp=0;
int main()
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements in the array\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	merge_sort(arr,0,n-1);
	cout<<"After Sorting: ";
	for(int j=0;j<n;j++)
		cout<<arr[j]<<" ";
	cout<<"Number of Comparisons Made are "<<comp;
}
void merge_sort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
void merge(int arr[],int p,int q,int r)
{
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[p+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=arr[q+i+1];
	}
	i=j=0;
	k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
		comp++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}
