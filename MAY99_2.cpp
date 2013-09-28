#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int t;
	char arr[5] = {'u','m','a','n','k'};
	scanf("%d",&t);
	long long int ten_18 = 1000000000;
	ten_18 *= ten_18;
	int maxlen = ceil(log(ten_18));
	
	char ans[maxlen];
	for(int i=0;i<t;i++)
	{
		long long int n;
		scanf("%lld",&n);
		//printf("%lld-\n",n);
		int len = 0;
		do
		{
			if(n%5==0)
				n = n-5;
			ans[len++] = arr[n%5];
			n /= 5;
		}while(n>0);
		
		for(int i= len-1;i>=0;i--)
		{
			putchar(ans[i]);
		}
		printf("\n");
	}
	return 0;
}
