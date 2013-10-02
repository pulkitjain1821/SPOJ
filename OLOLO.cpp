#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int x;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		ans ^= x;
	}
	printf("%d\n",ans);
	return 0;
}
