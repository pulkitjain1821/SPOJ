#include<cstdio>
#include<cstdlib>
using namespace std;
short ans[5001][5001];
int main()
{
	for(int i=0;i<=5000;i++)
	{

		ans[0][i] = 1;
	}
	
	for(int i=1;i<=5000;i++)
	{
		for(int j=1;j<=5000;j++)
		{
		/*	int k = 0;
			while(k<=i)
			{
				ans[i][j] = (ans[i][j] + ans[k][j-1])%1988;
				k++;
			}
		*/
			ans[i][j] = ans[i][j-1] ;
			if(i-j>=0)
			ans[i][j] =	(ans[i][j] + ans[i-j][j])%1988;
		}
	}
	
	/*for(int z=0;z<=4;z++)
	{
		for(int l=0;l<=4;l++)
		{
			printf("%d ",ans[z][l]);
		}
		printf("\n");
	}
	*/
	int n,k;
	while(true)
	{
		scanf("%d%d",&n,&k);
		if(n==0 && k==0)
			break;
		printf("%d\n",ans[n-k][k]);
	}
	return 0;
}
