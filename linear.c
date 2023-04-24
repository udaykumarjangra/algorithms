#include<stdio.h>
#include<stdlib.h>
void main()
{
	int arr[20],i,no,n,f=0,comp=0;
	printf("Enter the no.of elements required : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		arr[i] = rand();
	}
	printf("Array :");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	printf("Enter the element to search for : ");
	scanf("%d",&no);
	for(i=0;i<n;i++)
	{
		comp++;
		if(arr[i]==no){
			printf("Number is found on %d location.",i+1);
			f++;
			break;
		}
	}
	if(f==0){
		printf("Number not found");
	}
	printf("\ncomp = %d ",comp);
}
