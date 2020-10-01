#include<stdio.h>
int number=0;
void merge( int arr[], int left, int mid, int right)
{
	int i,j,k;
	int size1=mid-left+1;
	int size2=right-mid;
	int LArr[size1], RArr[size2];
	
	for( i=0; i<size1; i++)
	{
		LArr[i]=arr[left+i];
	}
	for( i=0; i< size2; i++)
	{
		RArr[i]=arr[mid+1+i];
	}
	i=0; j=0; k=left;
	while(i<size1 && j<size2)
	{
		if(LArr[i]<RArr[j])
		{
			arr[k]=LArr[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=RArr[j];
			k++;
			j++;
		}
		number++;
	}
	while(i<size1)
	{
		arr[k]=LArr[i];
		i++;
		k++;
		number++;
	}
	while(j<size2)
	{
		arr[k]=RArr[j];
		j++;
		number++;
		k++;
	}
}

void mergesort( int arr[], int left, int right)
{
	if( left < right)
	{
		int mid= (left+right)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		
		merge(arr,left,mid,right);
	}
}


int main()
{
	int no, i;
	printf("Enter number of elements you want to enter in the array\n");
	scanf("%d",&no);
	int arr[no];
	printf("Enter %d elements in array\n");
	for(i=0; i<no; i++)
	{
		//scanf("%d", &arr[i]);
		arr[i]=i;
	}
	printf("Given array is\n");
	for(i=0; i<no; i++)
	{
		printf("%d ",arr[i]);
	}
	
	mergesort(arr, 0, no-1);
	printf("Sorted array is\n");
	for(i=0; i<no; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nNumber of Comparisons are %d\n",number);
}
