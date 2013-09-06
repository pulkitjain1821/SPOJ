#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int aa,bb,cc;
	double a,b,c;
	double area,s;
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d",&aa,&bb,&cc);
		a = aa; b = bb; c = cc;  
	//	printf("%f %f %f\n",a,b,c);
		s = (a+b+c)/2;
	//	printf("Semiperimeter is %f\n",s);
		area = 0.5*(3*sqrt(s*(s-a)*(s-b)*(s-c))  +   sqrt(3)*(a*a + b*b + c*c)/4);
	//	printf("Area is %f\n",area);
		printf("%.2f\n",round(100*area)/100);
	}
	return 0;
}
