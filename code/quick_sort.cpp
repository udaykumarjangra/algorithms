#include<iostream>
using namespace std;
int partition(int arr[], int lb, int ub)
{	int pivot, start, end;
	pivot=arr[lb];
	start=lb;
	end=ub;
	while(start<end)
	{
		while(arr[start]<=pivot)
		{
			start++;
		}
		while(arr[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(arr[start],arr[end]);
		}
		return end;
	}
}
int quicksort(int arr[], int lb, int ub)
{	int loc;
	if(lb<ub)
	{
		loc=partition(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}
void swap(int *a, int *b)
{
	int temp=*a;
	*a =*b;
	*b=temp;
}
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
 
int main()  
{  
    int arr[] = {9,8,7,6,5,4,3,2,1,0};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quicksort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}
