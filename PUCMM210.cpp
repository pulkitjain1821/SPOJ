#include<cstdio>
#include<cstdlib>
#define mod 1000000003
using namespace std;
long long int power(long long int n, int x)
{
	//printf("Called\n");
	if(x==0)
	{
		return 1;
	}
	else if(x==1)
	{
		return n%mod;
	}
	else if(x==2)
	{
		return ((n%mod)*(n%mod))%mod;
	}
	else if(x%2==0)
	{
		return power(power(n,2),x/2);
	}
	else
	{
		long long int temp = power(n,x-1);
		return (temp*(n%mod))%mod;
	}
}

int main()
{
//invers modulo's calculated from http://www.cs.princeton.edu/~dsri/modular-inversion-answer.php

	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long int n;
		scanf("%lld",&n);
		long long int t4 = (( (6*power(n,5))%mod + (15*power(n,4))%mod + (10*power(n,3))%mod - (n%mod))*(766666669))%mod;		// 30 inverse % mod 
		//printf("t4 is %lld\n",t4);
		long long int t2 = (  (((n*(n+1))%mod)*((2*n + 1)%mod)%mod)*(833333336))%mod;											//6 inverse % mod
		//printf("t2 is %lld\n",t2);
		long long int t3 =  ((((n%mod)*(n%mod))%mod)*((((n+1)%mod)*((n+1)%mod))%mod))%mod;										
		t3 = (t3*500000002)%mod;																								//2 inverse % mod
		//printf("t3 is %lld\n",t3);
		long long int ans = (((t4 + t2 + t3)%mod)*(250000001))%mod;																//4 inverse % mod
		printf("%lld\n",ans);
	}
	return 0;
}
