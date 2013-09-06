#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long int n,k,T,f;
	long long int ans = 0;
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld%lld",&n,&k,&T,&f);
		ans = f + n*(1+k) - (n*k*k-f)/(k-1);
		printf("%lld\n",ans);
	}
	return 0;
}
