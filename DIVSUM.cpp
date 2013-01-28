#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
		{
			t--;
			int n;
			scanf("%d",&n);
			if(n==1)
				{
					printf("0\n");
					continue;
				}
			if(n==2)
				{
					printf("1\n");
					continue;
				}
			if(n==3)
				{
					printf("1\n");
					continue;
				}
			int sr = (int)sqrt(n);
			long long int ans =0;
			for(int i=2;i<=sr;i++)
				if(n%i==0)
					ans+= i + n/i;
			if(n==sr*sr)
					ans-= sr;
			ans++;
			printf("%lld\n",ans);
		}
 return 0;
}
