#include<stdio.h>
void main()
{
	int row,a,b,i;
	printf("Enter number of rows you want to print\n");
	scanf("%d",&row);
	for(i=1;i<=row;i++)
	{
		for(a=1;a<=row-i;a++)
		{
			printf(" ");
		}
		for(b=1;b<=(2*i-1);b++)
		{
			printf("*");
		}
		printf("\n");
	}
}
