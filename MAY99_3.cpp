#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int min,int max)
{
	if(max%min==0)
		return min;
	else
		return gcd(max%min,min);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z>x && z>y)
		{
			printf("NO\n");
			continue;
		}
		int g = gcd(min(x,y),max(x,y));
		if(z%g==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;	
}
