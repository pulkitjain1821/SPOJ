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
		double a,b,c,d;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		//printf("%.f%.f%.f%.f",a,b,c,d);
		double s = (a+b+c+d)/2;
		double area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2f\n",area);;
	}
	return 0;
}
