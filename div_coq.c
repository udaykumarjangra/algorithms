#include<stdio.h>
#include<stdlib.h> 
struct pair  
{ 
  int min; 
  int max; 
};   
  
struct pair getMinMax(int arr[], int n) 
{ 
  struct pair minmax;      
  int i; 
    
  if (n == 1) 
  { 
     minmax.max = arr[0]; 
     minmax.min = arr[0];      
     return minmax; 
  }     
  
  if (arr[0] > arr[1])   
  { 
      minmax.max = arr[0]; 
      minmax.min = arr[1]; 
  }   
  else
  { 
      minmax.max = arr[1]; 
      minmax.min = arr[0]; 
  }     
  
  for (i = 2; i<n; i++) 
  { 
    if (arr[i] >  minmax.max)       
      minmax.max = arr[i]; 
    
    else if (arr[i] <  minmax.min)       
      minmax.min = arr[i]; 
  } 
    
  return minmax; 
} 
  
int main() 
{ 
  int n,arr[5000],i;
  printf("enter the number of elements\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	arr[i]=rand();
  }
  printf("The numbers are\n");
  for(i=0;i<n;i++)
   
  {
  	printf("%d\n",arr[i]);
	} 
  struct pair minmax = getMinMax (arr, n); 
  printf("\nMinimum element is %d", minmax.min); 
  printf("\nThe maximun element is %d", minmax.max); 
  getchar(); 
}
