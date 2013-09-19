#include<cstdio>
#include<cstdlib>
#define max 1000001
using namespace std;
int main()
{
	int* isPrime = (int*)malloc(max*sizeof(int));
	for(int i=0;i<max;i++)
	{
		isPrime[i] = 1;
	}
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2;i<max;i++)
	{
		if(isPrime[i])
		{
			for(int j=2*i;j<max;j+= i)
			{
				isPrime[j] = 0;
			}
		}
	}
	
	int t;
	scanf("%d",&t);
	int start;
	int end;
	for(int i =0;i<t;i++)
	{
		scanf("%d%d",&start,&end);
		if(end<max)
		{
			//int ans = 0;
			for(int j=start;j<=end;j++)
			{
				if(isPrime[j])
					printf("%d\n",j);
			}
			printf("\n");
		}
		else
		{
			int count = 0;
			for(int j=start;j<max;j++)
			{
				if(isPrime[j])
					printf("%d\n",j);
			}
			
			int temp[end-start+1];
			for(int k = 0;k<=end-start;k++)
			{
				temp[k] = 1;
			}
		
			for(int i=2;i<max;i++)
			{
				if(isPrime[i])
				{
					int j = ((start + i-1)/i)*i;
					for(;j<=end;j+=i)
					{
						temp[j-start] = 0;
					}
				}
			}
			for(int k = 0;k<=end-start;k++)
			{
				if(temp[k])
					printf("%d\n",k+start);
			}
			printf("\n");
		}
	}
	return 0;
}
