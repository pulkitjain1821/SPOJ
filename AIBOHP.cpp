#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char arr[6101];
	short **ans = (short**)malloc(6100*sizeof(short*));
	for(int i=0;i<6100;i++)
	{
		*(ans+i) = (short*)malloc(6100*sizeof(short));
	}
	for(int i =0;i<t;i++)
	{
		scanf("%s",arr);
		int n = strlen(arr);
		for(int i=0;i<n;i++)
		{
			ans[i][i] = 0;
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=0;i+len-1<n;i++)
			{
				if(arr[i]==arr[i+len-1])
				{
					if(len==2)
					{
						ans[i][i+len-1] = 0;
					}
					else
					{
						ans[i][i+len-1] = ans[i+1][i+len-2];
					}
				}
				else
				{
					ans[i][i+len-1] = min(1+ans[i][i+len-2],1+ans[i+1][i+len-1]);
				}
			}
		}
		printf("%d\n",ans[0][n-1]);
	}
	return 0;
}

