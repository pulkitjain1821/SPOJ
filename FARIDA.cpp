#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,num;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		long long int d_n = 0;
		long long int d_nn = 0;
		long long int curr = 0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&num);
			curr = max(d_n ,d_nn+num);	
			d_nn = d_n;
			d_n = curr;
		}
		printf("Case %d: %lld\n",i+1,curr);
	}
	return 0;
}
