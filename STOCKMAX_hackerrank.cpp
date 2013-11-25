#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t,n;
	long long int ans = 0;
	int arr[50000];
	int best = 0;
	scanf("%d",&t);
	for(int l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",arr+i);
		}
		best = 0; ans = 0;
		for(int i=n-1;i>=0;i--)
		{
			ans += max(0,best-arr[i]);
			best = max(best,arr[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
