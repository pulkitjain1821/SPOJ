#include <cstdio>
#define mod 10000007
using namespace std;

long long int power(long long int b, long long int e)
{
	if(b==0||b==1)
		return b;
	if(e==1)
		return b%mod;
	if(e==2)
		return ((b%mod)*(b%mod))%mod;
	if(e%2==1)
		return ((b%mod)*(power(power(b,e/2)%mod,2)%mod))%mod;
	else
		return power(power(b,e/2)%mod,2)%mod;
}

int main()
{
	long long int n=5;
	long long int k=2;
	
	while(1)
		{
			
			long long int n;
			long long int k;
			scanf("%lld%lld",&n,&k);
			if(n==0 && k==0)
				break;
			long long int ans = ((power(n,n) + (2*power(n-1,n-1)))%mod + (power(n,k) + (2*power(n-1,k)))%mod)%mod;
			printf("%lld\n",ans); 
		}
	return 0;
}
