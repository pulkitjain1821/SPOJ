#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	double n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lf",&n);
		printf("%.8f\n",1-(1/(n+1)));
	}
	return 0;
}
