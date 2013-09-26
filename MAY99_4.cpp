#include<cstdio>
#include<cstdlib>
#define mod 10000007
using namespace std;

long long int power(long long int a, int x)
{
	if(x==0)
		return 1;
	else if(x==1)
	{
		return a%mod;
	}
	else if(x==2)
	{
		long long int temp = ((a%mod)*(a%mod))%mod;
		return temp;
	}
	else if(x%2==0)
	{
		return power(power(a,2),x/2);
	}
	else
	{
		long long int temp = power(a,x-1);
		temp = (temp*(a%mod))%mod;
		return temp;
	}
}

long long int inverse(long long int a)
{
	return power(a,9988439)%mod;				//euler phi (10000007) = 9989380
}

int main()
{
	/*printf("%lld-->\n",power(2,100));
	printf("%lld-->\n",power(21,2));
	printf("%lld-->\n",power(34,5));
	printf("%lld-\n",inverse(3L));
	printf("%lld-\n",inverse(1L));
	printf("%lld-\n",inverse(2L));
	*/
	long long int n;
	long long int r;
	scanf("%lld%lld",&n,&r);
	
	n = n-1;
	r = r-1;
	if(r>n)
		printf("-1\n");
	else
	{
		if(r>n/2)
			r = n-r;
		long long int ans = n;
		if(r==0)
			ans = 1;
		else
		{
			for(long long int i=1;i<r;i++)
			{
				ans = (((ans*(n-i))%mod)*inverse(i+1))%10000007;
			}
		}
		printf("%lld\n",ans%10000007);
	}
	return 0;	
}
