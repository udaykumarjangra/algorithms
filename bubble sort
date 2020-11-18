#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int bubble_sort(int arr[], int n) 
{
	int i,temp, j,flag;
	system("cls");
	for(i=0;i<n;i++) 
		{
			flag = 0;
			for(j=0;j<(n-i-1);j++)  
				{   
					if(arr[j] > arr[j+1])
						{   flag = 1;
							temp = arr[j+1];    
							arr[j+1] = arr[j];    
							arr[j] = temp;
						}
				}
			if(flag==0){
				cout<<"\n The array sorted in ascending order is :\n"<<endl;
				for(i=0;i<n;i++)
				cout<<arr[i]<<"\t";
				cout<<endl;
				system("pause");
				return 0;
			}
		}
	cout<<"\n The array sorted in ascending order is :\n"<<endl;
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	cout<<endl;
	system("pause");
 return 0;
}
