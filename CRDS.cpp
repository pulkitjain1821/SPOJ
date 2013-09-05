#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long int n;
		scanf("%lld",&n);
		long long int ans = (n*(n+1) + (n-1)*(n)/2)%1000007;
		printf("%lld\n",ans);
	}
	return 0;
}
