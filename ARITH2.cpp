#include <cstdlib>
#include <cstdio>

using namespace std;

long long int operate(long long int a, long long int b, char c)
{
  if(c=='-')
		return a-b;
	if(c=='+')
		return a+b;
	if(c=='*')
		return a*b;
	if(c=='/')
		return a/b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		long long int ans = 0;
		char op;
		int iter = 0;
		while(1)
		{
			long long int x;
			char c;
			scanf("%lld",&x);
			while((c=getchar())== ' ')
			{
			}
			
			if(iter==0)
				{
					ans = x;
					op = c;
				}
			else
			{
				ans = operate(ans,x,op);
				op = c;
			}	
			if(op == '=')
				break;
			iter++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
