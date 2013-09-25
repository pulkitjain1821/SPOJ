#include<cstdio>
#include<cstdlib>
#define max  1000000
#define size 1000000
using namespace std;
int main()
{
	bool* isPrime = (bool*)malloc((max+1)*sizeof(bool));
	int* nfactor = (int*)malloc((size+1)*sizeof(int));
	int ** count = (int**)malloc((size+1)*sizeof(int*));
	for(int i=0;i<=size;i++)
	{
		*(count+i) = (int*)malloc(10*sizeof(int));	
	}

	for(int i=0;i<=max;i++)
	{
		isPrime[i] = true;
	}

	for(int i=0;i<=size;i++)
	{
		nfactor[i] = 0;
	}

	isPrime[0] = isPrime[1] = false;
	for(long long int i=2;i<=max;i++)
	{
		if(isPrime[i])
		{
			long long int j;
			nfactor[i]++;
			for(j=2*i;j<=max;j+=i)
			{
				isPrime[j] = false;
				nfactor[j]++;
			}
		}
	}
	
	int tcount[10] = {0};
	for(int m=0;m<10;m++)
	{
		count[0][m] = 0;
	}
	for(int i=1;i<=size;i++)
	{
		if(nfactor[i]>0 && nfactor[i]<=10)
		{
			tcount[nfactor[i]-1]++;
			for(int k=0;k<10;k++)
			{
				count[i][k] = tcount[k];
			}
		}
	}


	/*for(int i=0;i<=20;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d ",count[i][j]);
		}
		printf("\n");
	}*/

	/*
	for(int i=size-20;i<=size;i++)
	{
		printf("%d is prime  = %d\n",i,isPrime[i]==true?1:0);
		printf("%d has %d prime factors\n",i,nfactor[i]);
	}*/
	
	int t;
	scanf("%d",&t);
	int n,a,b;
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d",&a,&b,&n);
		if(n==0)
		{
			if(a>1)
				printf("0\n");
			else
				printf("1\n");
		}
		else
		{
			printf("%d\n",count[b][n-1]-count[a-1][n-1]);
		}	
	}
	return 0;
}
