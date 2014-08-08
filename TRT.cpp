#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long int sum[2000][2000];
int sumarr[2001];
int sumno(int i1, int i2)
{
	return sumarr[i2+1] - sumarr[i1];
}
int main()
{
	int n;
	scanf("%d",&n);
	long long int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",arr+i);
		sumarr[i+1]= sumarr[i] + arr[i];
	}
	for(int i=0;i<n;i++)
	{
		sum[i][i] = arr[i];
	}
	
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i+l-1<=n-1;i++)
		{
			sum[i][i+l-1] = max(arr[i]+sum[i+1][i+l-1]+sumno(i+1,i+l-1),arr[i+l-1]+sum[i][i+l-2]+sumno(i,i+l-2));
		}
	}

	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%lld ",sum[i][j]);
		}
		printf("\n");
	}*/

	printf("%lld\n",sum[0][n-1]);
	return 0;
}


