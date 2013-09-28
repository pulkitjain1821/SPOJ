/*
Think it as to go from node 0 to node dest
ways are equivalent = going from 1 to dest with k-1 steps + going from n-1 to dest with k-1 steps.
*/

#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	
	int n,k;
	while(true)
	{
		scanf("%d%d",&n,&k);
		if(n==-1 && k==-1)
			break;
		int a,b;
		scanf("%d%d",&a,&b);

		long long int** arr = (long long int**)malloc((k+1)*sizeof(long long int*));
		for(int i=0;i<=k;i++)
		{
			arr[i] = (long long int*)malloc(n*sizeof(long long int));
		}		
		for(int i=0;i<n;i++)
		{
			arr[0][i] = 0;
		}
		arr[0][0] = 1;
		
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j] = arr[i-1][(int)abs(1-j)] + arr[i-1][(int)abs(n-1-j)];
			}
		}
		printf("%lld\n",arr[k][(int)abs(a-b)]);
	}
	return 0;
}
