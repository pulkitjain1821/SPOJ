#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		double p0,p1,t,p;
		scanf("%lf%lf%lf%lf",&p0,&p1,&t,&p);
		double k = log(p1/p0)/t;
		t = log(p/p0)/k;
		printf("Scenario #%d: %.2f\n",i+1,round(100*t)/100);
	}
	return 0;
}
