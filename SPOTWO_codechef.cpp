#include<cstdlib>
#include<cstdio>
#include<cmath>
#define mod 1000000007
using namespace std;

unsigned long long int conv (int n)
{
	unsigned long long int ans = 0;
	int trail = 0;
	while(n%2==0)
	{
		n/=2;
		trail++;
	}
	while(n>0)
	{
		ans = ans*10 + n%2;
		n/=2;
	}
	unsigned long long int final = 0;
	while(ans>0)
	{
		final = final*10 + ans%10;
		ans /= 10;
	}
	while(trail > 0)
	{
		final *=10;
		trail--;
	}
	return final;
}

int pow(unsigned long long int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	if(n%2==0)
	{
		long long int ans = pow(n/2);
		return (ans*ans)%mod;
	}
	else
	{
		long long int ans = pow(n/2);
		return (2*ans*ans)%mod;
	}
}


int main()
{
	//printf("%.6f\n",log(2*600000)/log(2));
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		long long int temp = pow(conv(n));
		temp *= temp;
		temp %=mod;
		printf("%lld\n",temp);
	}
	return 0;
}
