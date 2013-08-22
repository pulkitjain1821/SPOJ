#include<cstdlib>
#include<cstdio>
using namespace std;

long long int gcd(long long int x, long long int y )
{
	if(x%y==0)
		return y;
	else
		return gcd (y, x%y);
}

void coprime(long long int num )
{
	for(long long int i = num/2;i>=1;i--)
		{
			if(gcd(i,num)==1)
			{
				printf("%lld\n",i);
				break;
			}
		}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		long long int n;
		scanf("%lld",&n);
		coprime(n);
	}
	return 0;
}
