#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
  int t;
	scanf("%d",&t);
	int i=0;
	while(i<t)
	{
		i++;
		long long int r;
		scanf("%lld",&r);
		printf("Case %d: %lld.25\n",i,4*r*r);
	}
	return 0;
}
