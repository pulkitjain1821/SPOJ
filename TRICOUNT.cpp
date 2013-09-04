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
			printf("%lld\n",(n*(n+2)*(2*n+1))/8);
		}
	return 0;
}

