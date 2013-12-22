#include<cstdlib>
#include<cstdio>
#define mod 314159
using namespace std;
long long int pow(long long int a,long long int b)
{
	a = a%mod;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	long long int temp = pow((a*a)%mod,b/2);
	if(b%2==0)
	{
		return temp;
	}
	else
	{
		return (a*temp)%mod;		
	}
}

int main()
{
	long long int t,n;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		long long int ans = (pow(8,n)+pow(10,n))%mod;
		ans *= (mod/2) + 1;
		ans = ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
