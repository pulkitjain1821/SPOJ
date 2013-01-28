#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
		{
			t--;
			long long int n;
			scanf("%lld",&n);
			if(n&1)
				printf("%lld\n",((n+1)/2-1)*500 + 192);
			else
				printf("%lld\n",(n/2-1)*500 + 442);
		}
	return 0;
}
