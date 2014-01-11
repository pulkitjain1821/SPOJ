/* help taken from http://apps.topcoder.com/forums/?module=Thread&threadID=752493&start=0&mc=5 */

#include<cstdio>
#include<cstdlib>
using namespace std;
int arr[1000];
bool sum[1000][1001];
void reset(int n,int k)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			sum[i][j] = false;
		}
	}
}
int main()
{
	int n,k,t;
	scanf("%d",&t);
	for(int l=0;l<t;l++)
	{
		scanf("%d%d",&n,&k);
		reset(n,k);
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
		for(int i=0;i<n;i++)
		{
			sum[i][0] = true;
		}
		if(arr[0] <= k)
			sum[0][arr[0]] = sum[1][arr[0]] = true;
		if(arr[1] <= k)
			sum[1][arr[1]] = true;

		for(int i=2;i<n;i++)
		{
			for(int s=1;s<=k;s++)
			{          
				sum[i][s] = sum[i-1][s];
				if(s-arr[i]>=0)
				{
					sum[i][s] =  sum[i][s] || sum[i-2][s-arr[i]];
				}
			}
		}
		int ans ;
		for(ans = k;ans>=0;ans--)
		{
			if(sum[n-1][ans])
				break;
			
		}
		printf("Scenario #%d: %d\n",l+1,ans);
	}
	return 0;
}
