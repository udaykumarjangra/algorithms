// Program to sort array of 0s,1s and 2s.
#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n)
{
    int low=0,high=n-1;
    int mid=0;
    while(mid<=high)
    {
        switch(a[mid])
        {
            case 0: swap(a[low],a[mid]);
                    low++,mid++;
                    break;
            case 1: mid++;
                    break;
            case 2: swap(a[mid],a[high]);
                    high--;
                    break;
        }
    }
 }
int main()
{
    int n;
    cout<<"Enter No. Of Elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0; 
}
