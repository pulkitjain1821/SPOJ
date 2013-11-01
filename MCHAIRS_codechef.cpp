#include<cstdio>
#include<cstdlib>
#define mod 1000000007
using namespace std;

int power(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	if(n%2==0)
	{
		long long int ans =  power(n/2);
		ans *= ans;
		return ans%mod;
	}
	else
	{
		long long int ans =  power(n/2);
		ans *= 2*ans;
		return ans%mod;		
	}
}

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int ans = (power(n) - 1)%mod;
		printf("%d\n",ans);
	}
	return 0;
}
