#include<cstdlib>
#include<cstdio>
#define max 100000
using namespace std;
int main()
{
	bool* isPrime = (bool*)malloc((max+1)*sizeof(int));
	int**  pfactors = (int**)malloc((max+1)*sizeof(int*));
	for(int i=0;i<=max;i++)
	{
		*(pfactors+i) = (int*)malloc(7*sizeof(int));
	}
		
	for(int i=0;i<=max;i++)
	{
		isPrime[i] = true;
		for(int j=0;j<7;j++)
		{
			pfactors[i][j] = 0;
		}
	}	

	isPrime[0] = isPrime[1] = false;
	for(int i =2;i<=max;i++)
	{
		if(isPrime[i])
		{
			for(int j=2*i;j<=max;j+=i)
			{
				isPrime[j] = false;
			}
			for(int j=i;j<=max;j+=i)
			{
				pfactors[j][0]++;
				pfactors[j][pfactors[j][0]] = i;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		
		int x = 1; int ans = m;
		int limit = 1<<pfactors[n][0];
		for(;x<limit;x++)
		{
			int count = 0;int div = 1;
			for(int i=0;i<=5;i++)
			{
				if(x&1<<i)
				{
					div *= pfactors[n][i+1];
					count++;
				}
			}
			if(count&1)
			{
				ans -= m/div;
			}
			else
			{
				ans += m/div;
			}
		}
		printf("%d\n",ans);
	}
	
	/*for(int i=1;i<=30;i++)
	{
		printf("%d -> ",i);
		for(int j=1;j<=pfactors[i][0];j++)
		{
			printf("%d ",pfactors[i][j]);
		}
		printf("\n");
	}

	int mmax = 0; int c=0;
	for(int i=0;i<=max;i++)
	{
		if(mmax<nfactor[i])
			{
				mmax = nfactor[i];
				c = i;
			}
	}*/

	//printf("%d for %d\n",mmax,c);
	return 0;
}
