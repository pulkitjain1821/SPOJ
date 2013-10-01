#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int arr [10001];
	bool isPrime[10001];
	for(int i=0;i<=10000;i++)
	{
		isPrime[i] = false;
		isPrime[i|1] = true;
		arr[i] = i;
	}
	isPrime[1] = false;
	isPrime[2] = true;
	for(int i=2;i<=10000;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=10000;j+=2*i)
			{
				isPrime[j] = false;
			}
			for(int j=i;j<=10000;j+=i)
			{
				arr[j] -= (arr[j]/i);
			}
		}
	}
	for(int i =1;i<=10000;i++)
	{
		arr[i] += arr[i-1];
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		long long int ans = arr[n];
		printf("%lld\n",ans*ans);
	}
	return 0;
}
