/* similar to the matrix multiplication DP problem */

#include<cstdio>
#include<cstdlib>
using namespace std;
int arr[100];
int val[100][100];
int smoke[100][100];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",arr+i);
		}
		for(int i=0;i<n;i++)
		{
			val[i][i] = arr[i];
			smoke[i][i] = 0;
		}
		for(int i=0;i+1<n;i++)
		{
			val[i][i+1] = (arr[i]+arr[i+1])%100;
			smoke[i][i+1] = arr[i]*arr[i+1];
		}
		
		for(int l=3;l<=n;l++)
		{
			for(int j=0;j+l-1<n;j++)
			{
				int min = 1000000000;
				int value;
				for(int k=j;k<j+l-1;k++)
				{
					if(min > smoke[j][k] + smoke[k+1][j+l-1] + val[j][k]*val[k+1][j+l-1])
					{
						min = smoke[j][k] + smoke[k+1][j+l-1] + val[j][k]*val[k+1][j+l-1];
						value = (val[j][k] + val[k+1][j+l-1])%100;
					}
				}
				val[j][j+l-1] = value;
				smoke[j][j+l-1] = min;
			}
		}
		printf("%d\n",smoke[0][n-1]);
	}
	return 0;
}
