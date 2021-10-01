#include<iostream>
using namespace std;
int leftChild(int i)
{
    return 2*i+1;
}
int rightChild(int i)
{
    return 2*i+2;
}
void minHeapify(int arr[],int i,int heapsize)
{
    int l,r,smallest;
    l=leftChild(i);
    r=rightChild(i);
    if(l<=heapsize && arr[l]<arr[i])
    {
        smallest=l;
    }
    else
    {
        smallest=i;
    }
    if(r<=heapsize && arr[r]<arr[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        minHeapify(arr,smallest,heapsize);
    }
    
}
void buildMinHeap(int arr[],int n)
{
    int heapsize=n;
    for(int i=n/2;i>=0;i--)
    {
        minHeapify(arr,i,heapsize);
    }
}
void heapSort(int arr[],int n)
{
    int heapsize=n;
    buildMinHeap(arr,n);
    for(int i=n;i>0;i--)
    {
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapsize=heapsize-1;
        minHeapify(arr,0,heapsize);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    heapSort(arr,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
