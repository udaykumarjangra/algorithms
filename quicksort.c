#include<stdio.h>
void quicksort(int arr[], int up, int down)
{	
	int i;
	if(up<down)
	{	
		i=partition(arr,up,down);
		quicksort(arr,up,i-1);
		quicksort(arr,i+1,down);
	}
}
void swap(int *a, int *b)
{
	int temp=*a;
	*a =*b;
	*b=temp;
}
int partition(int arr[], int up, int down)
{
	int pivot, u, d;
	pivot=arr[up];
	u=up;
	d=down;
	while(1)
	{
		while(arr[u]<=pivot)
		{
			u++;
		}
		while(arr[d]>pivot)
		{
			d--;
		}
		if(u<d)
		{
			swap(&arr[u],&arr[d]);
		}
		else if(d<u)
		{
			swap(&arr[up],&arr[d]);
			return d;
		}
	}
}

void display(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{	
	int n,i;
	printf("Enter number of elements in array to sort\n");
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array is\n");
	display(arr,n);
	quicksort(arr,0,n-1);
	printf("Sorted Array is\n");
	display(arr,n);
}
