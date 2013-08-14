#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		long long int rob;
		long long int k;
		scanf("%lld%lld",&rob,&k);
		long long int final[k];
		
		long long int n = (sqrt(1 + 8*rob) - 1)/2;
		while(n*(n+1)<=2*rob)
		{
			n++;
		}
		n--;
		long long int fullcycles = n/k;
		
		for(int i=0;i<k;i++)
			{
				final[i] = ((2*(i+1) + (fullcycles-1)*k)*fullcycles)/2;
				rob -= final[i];
			}
		int i=0;
		while(rob >= (i+1) + (fullcycles)*k)
		{
			final[i] += (i+1) + (fullcycles)*k;
			rob -=(i+1) + (fullcycles)*k;
			i++;
		}	
		final[i] += rob;
		for(int m=0;m<k;m++)
			printf("%lld ",final[m]);
		printf("\n");
	
	}
	return 0;
}
