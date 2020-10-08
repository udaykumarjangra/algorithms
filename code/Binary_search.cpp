//WAP to implement binary search and show the relation between the location of the element and the number of comparisons made.
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,arr[50],s,com,l,h,mid;
	int op,f,temp;
	printf("Enter the size of the dataset: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	/*for(int i=0;i<n;i++)
		printf("%d",arr[i]);*/
	do{	
		l=0;
		h=n-1;
		f=0;
		com=0;
		printf("Enter the element to search: ");
			scanf("%d",&s);

		while(l<=h)
		{
			mid=(l+h)/2;
			if(s==arr[mid])
			{
				f=1;
				com++;
				printf("Found! at %d",mid+1);
				printf("\nNumber of comparisons made =%d",com);
				break;
			}
			else if(s>arr[mid])
			{
				com++;
				l=mid+1;
			}
			else if(s<arr[mid])
			{
				com++;
				h=mid-1;
			}	
		}
		if(f==0)
			printf("Not Found!");
		printf("\nPress 1 to continue: ");
		scanf("%d",&op);
	}while(op==1);
}
