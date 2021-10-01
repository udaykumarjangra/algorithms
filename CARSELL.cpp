#include<stdio.h>
const unsigned int M = 1000000007;
void check(long long int *a,long long int n);
long long int max(long long int *a,long long int n);
int main()
{
	long long int i,t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int p[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&p[i]);
		}
		check(&p[0],n);
	}
	return 0;
}
void check(long long int *a,long long int n)
{
	long long int i,sum=0,maximum;
	for(i=0;i<n;i++)
	{
		maximum=max(a,n);	
		if((sum+maximum)>=M)
		{
			sum=((sum%M + maximum%M)%M);
		}
		else
		{
			sum+=maximum;
		}
	}
	printf("%lld\n",sum);
}
long long int max(long long int *a,long long int n)
{
	long long int maxim,i,j=0;
	maxim=((*(a+0))%M);
	for(i=0;i<n;i++)
	{
		if(maxim<((*(a+i))%M))
		{
			maxim=((*(a+i))%M);
			j=i;
		}
	}
	(*(a+j))=0;
	for(i=0;i<n;i++)
	{
		if((*(a+i))>0)
		{
			(*(a+i))-=1;	
		}
	}
	return maxim;
}
