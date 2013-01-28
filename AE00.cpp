#include <cstdio>
#include <cmath>
using namespace std;

int ways(int x)
{
	int sr = (int)sqrt(x);
	int count =0;
	if(x==1||x==2|x==3)
		return 1;
	int i=1;
	while(i<=sr)
		{
			if(x%i==0)
				count++;
			i++;
		}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long int ans=0;
	while(n>0)
	{
		int r = ways(n);
		//printf("%d--ways(%d)\n",r,n);
		ans+=r;
		n--;
	}
	printf("%lld\n",ans);
	return 0;
}
