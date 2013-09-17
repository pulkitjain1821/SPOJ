/* using long long int is also fine. Checked later*/


#include<cstdio>
#include<cstdlib>
using namespace std;

unsigned long long int factorial(int x)
{
	unsigned long long int res = 1;
	for(int i = 2;i<=x;i++)
	{
		res *= i;
	}
	return res;
}

unsigned long long int choose(int n, int r)
{
	if(n>0 && r==0)
		return 1;
	if(r > n/2)
		return choose(n, n-r);
	unsigned long long int res = n;
	for(int i=1;i<r;i++)
	{
		res = (res*(n-i))/(i+1);
	}
	return res;
}

int main()
{
	int i,j;	
	unsigned long long int dear[21];
	dear[0] = dear[1] = 0;
	for(i=2;i<=21;i++)
	{
		unsigned long long int sub = 0;
		for(j = 1;j<=i-2;j++)
		{
			sub += choose(i,j)*dear[i-j];
		}
		unsigned long long int fact = factorial(i);
		dear[i] = fact - sub - 1;
	}
	int t;
	scanf("%d",&t);
	int x;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&x);
		printf("%llu\n",dear[x]);
	}	
	return 0;
}
