/*
Workout to calculte 

F(n) = 2*f(n) - (n+2)

f(n)  = nth fibonacci
*/


#include<cstdio>
#include<cstdlib>
using namespace std;

void power(long long int arr[][2],int n, int mod)
{
//	printf("power(arr,%d,%d)\n",n,mod);
	if(n==0)
	{
		arr[0][0] = arr[1][1] = 1;
		arr[1][0] = arr[0][1] = 0;
	}
	else if(n==2)
	{

		long long int temp1[2][2];
		long long int temp2[2][2];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				temp2[i][j] = temp1[i][j] = arr[i][j]%mod;
			}
		}

		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				long long int n=0;
				for(int k=0;k<2;k++)
				{
					n+= (temp1[i][k]*temp2[k][j])%mod;
					n%= mod;
				}
				arr[i][j] = n;
			}
		}		
	}
	else if(n>2)
	{
//		printf("printing n&1 = %d\n",n&1);
		if(!(n&1))
		{
//			printf("Came here!!\n");
			power(arr,2,mod);
			power(arr,n/2,mod);
		}
		else
		{
			long long int temp1[2][2];
			long long int temp2[2][2];
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					temp1[i][j] = arr[i][j]%mod;
				}
			}
			power(arr,n-1,mod);
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					temp2[i][j] = arr[i][j]%mod;
				}
			}
	
	
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					long long int n=0;
					for(int k=0;k<2;k++)
					{
						n+= (temp1[i][k]*temp2[k][j])%mod;
						n%= mod;
					}
					arr[i][j] = n;
				}
			}
		}
	}
}

void display(long long int arr[][2])
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n, m;
		scanf("%d%d",&n,&m);
		//printf("%d--%d recieved\n",n,m);
		long long int arr[2][2] = {{1,1},{1,0}};
		power(arr,n+1,m);	
		long long int fib = arr[0][0];
		long long int ans = (2*fib - (n + 2))%m;
		printf("%lld\n",(ans+m)%m);
	}
	return 0;
}
