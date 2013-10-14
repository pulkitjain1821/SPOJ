#include<cstdio>
#include<cstdlib>
#define max 1000000
using namespace std;

int euler(int n)
{
	int ans  = n;
	for(long long int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n /= i;
			}
			ans -= ans/i;
		}
	}
	if(n>1)
		ans -= ans/n;

	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int s;
		scanf("%d",&s);
		printf("%d\n",euler(s));
	}
	return 0;
}

