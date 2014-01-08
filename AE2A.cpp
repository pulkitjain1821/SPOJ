/*The limits 550 and 3300 were told by some guy who had already solved the problem*/

#include<cstdlib>
#include<cstdio>
using namespace std;
long double arr[551][3301] = {0};
/*int getAns(int n,double val)
{
	while(n>0)
	{
		val/=6;
		n--;
	}
	printf("%lf --\n",val);
	int ans = val;
	return ans;
}*/
int main()
{
	for(int i=1;i<=6;i++)
	{
		arr[1][i] = 1.0/6.0;
	}
	for(int i=2;i<=550;i++)
	{
		for(int j=2;j<=3301;j++)
		{
			for(int k=1;k<=6;k++)
			{
				if(j-k>=0)
				{
					arr[i][j] += arr[i-1][j-k]/6.0;
				}
			}
		}
	}
	
	/*for(int l=1;l<=13;l++)
	{
		for(int z = 1;z<=13;z++)
		{
			printf("%.2lf ",arr[l][z]);
		}
		printf("\n");
	}*/
	int t;
	scanf("%d",&t);
	int n,k;
	for(int l=0;l<t;l++)
	{                  
		scanf("%d%d",&n,&k);
		if(n<=550 && k<=3300)
		{
			printf("%d\n",(int)(100*arr[n][k]));
			//printf("%d\n",getAns(n,100*arr[n][k]));
		}
		else
			printf("0\n");
	}
	return 0;
}
