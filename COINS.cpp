#include<stdio.h>
#include<stdlib.h>
int *ans;
long long int ex(long int N)
{
	if(N<1000000)
		return ans[N];
	else
	{
		long long int t = ex(N/2) + ex(N/3) + ex(N/4);
		if(N < t)
			return t;
		else
			return N;
	}	
}
int main()
{
	
	ans = (int*)malloc(1000000*sizeof(int));
 
	ans[0]=0;
	ans[1]=1;
	ans[2]=2;
	ans[3]=3;
	ans[4]=4;
	int i;
	for(i=5;i<1000000;i++)
		{
		int k = ans[i/2] + ans[i/3] + ans[i/4];
		if(i < k )
			ans[i] = k;
		else
			ans[i] = i;
		}
 
	long long int n;
	int count=0;
	while(scanf("%lld",&n)!=EOF && count < 10)
	{
		count++;
		printf("%lld\n",ex(n));
	}
	return 0;
 
 
 
}
 
