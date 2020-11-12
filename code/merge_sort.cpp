#include<iostream>
using namespace std;
void merge(int a[],int si,int ei,int mi)
{
	int p,q,k=0;
	p=si;
	q=mi+1;
	int arr[ei-si+1];
	for(int i=si;i<=ei;i++)
	{
	    if(p>mi)
	       arr[k++]=a[q++];
	    else if(q>ei)
	       arr[k++]=a[p++];
	    else if(a[p]<a[q])
	        arr[k++]=a[p++];
	    else
	        arr[k++]=a[q++];    	
	}
//	si=0;
	for(int p=0;p<k;p++)
	{
		a[si++]=arr[p];
	}
}
void merge_sort(int a[],int si,int ei)
{
	int mid=(si+ei)/2;
	if(si>=ei)
	{
		return;
	}
	merge_sort(a,si,mid);
	merge_sort(a,mid+1,ei);
	merge(a,si,ei,mid);	

}
int main()
{
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	int a[n];
	cout<<endl<<"Enter elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	merge_sort(a,0,n-1);
	cout<<endl<<"sort:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<endl;
	}
}
