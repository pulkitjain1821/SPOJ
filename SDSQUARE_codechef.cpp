#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
bool perf(long long int n)
{
	while(n>0)
	{
		int dig = n%10;
		if(dig!=0 && dig!=1 && dig!=4 && dig!=9)
			return false;
		n /=10;
	}
	return true;
}
int main()
{
	long long int perfs[125];
	int iter = 0;
	for(long long int i = 1;i<=100000;i++)
	{
		if(perf(i*i))
		{
			perfs[iter++] = i*i;
		}
	}

	
	int t;
	scanf("%d",&t);
	
	long long int a,b,count;
	for(int j=0;j<t;j++)
	{
		count = 0;
		scanf("%lld%lld",&a,&b);
		for(int i=0;i<iter;i++)
		{
			if(perfs[i]>=a && perfs[i]<=b)
				count++;
			if(perfs[i]>b)
				break;
		}
		printf("%lld\n",count);
	}
}
