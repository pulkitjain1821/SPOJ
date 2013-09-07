#include<cstdio>
#include<cstdlib>
#include<cmath>
#define pi 3.141592653589793
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long int num;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&num);
		if(num<3)
		{
			printf("1\n");
		}
		else
		{
			double ans = floor((num*log(num)-num+(log(2.0*pi*num))/2.0)/log(10.0))+1.0;
			printf("%.0lf\n", ans + 1e-12);
		}
	}
	return 0;
}
