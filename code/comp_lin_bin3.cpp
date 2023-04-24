//WAP to compare lin and bin search
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("  Pos   Lin   Bin\n");
	int n=10000,s,arr[10000],arr2[10000],com1,com2,pos;
	int loc=-1;
	int l,h,mid,temp;
	for(int i=0;i<10000;i++)
	{
		arr[i]=rand();
		arr2[i]=arr[i];
	}

	for(int i=0;i<10000;i++)//Sorting for Bin
		for(int j=0;j<10000;j++)
		{
			if(arr2[i]<arr2[j])
			{
				temp=arr2[i];
				arr2[i]=arr2[j];
				arr2[j]=temp;
			}
		}
	int ind[8]={1,10,50,100,500,1000,5000,10000};
	for(int t=0;t<8;t=t+1)
	{
		pos=ind[t]-1;
		s=arr[pos];
		com1=com2=0;
		loc=-1;
		l=0;
		h=n-1;
		com2=0;
		//Linear Search
		for(int i=0;i<n;i++)
		{
			if(s==arr[i])
			{
				loc=1;
				com1++;
				break;
			}
			else
				com1++;
		}
		//Binary Search
		while(l<=h)
		{
			mid=(l+h)/2;
			if(s==arr2[mid])
			{
				com2++;
				break;
			}
			else if(s>arr2[mid])
			{
				com2++;
				l=mid+1;
			}
			else if(s<arr2[mid])
			{
				com2++;
				h=mid-1;
			}	
		}
		printf("%5d %5d %5d\n",pos+1,com1,com2);
	}
}
