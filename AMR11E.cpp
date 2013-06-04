#include<cstdio>
#include<cstdlib>
#include<cmath>

void create_primes(int* primes,int n)
{
  primes[0]=2;
	primes[1]=3;
	primes[2]=5;
	primes[3]=7;
	primes[4]=11;
	int num =13;
	int cnt = 5;
	
	while(cnt<n)
	{
		int j =0;
		int prime = 1;
		while(primes[j] <= sqrt(num))
		{
			if(num%primes[j]==0)
			{
				prime=0;
				break;
			}
			j++;
		}
		if(prime==1)
			primes[cnt++]=num	;
		
		num += 2;
	}

}

void gen_lucky (int* arr,int* primes)
{
 arr[0] = 30;
 arr[1] = 42;
 int num = 43;
 int cnt = 2;
	
	while(cnt<1000)
	{
		int j =0;
		int pfactors = 0;
		while(primes[j] <= num/2)
		{
			if(num%primes[j]==0)
				pfactors++;
			j++;
		}
		if(pfactors>=3)
			arr[cnt++]=num	;
		
		num ++;
	}
	
}

int main()
{
	int primes[100];
	create_primes(primes,100);
	int lucky[1000];
	gen_lucky(lucky,primes);
//	for(int k=0;k<100;k++)
//		printf("%d\n",primes[k]);
	
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",lucky[k-1]);
	}
	return 0;	
	//system("PAUSE");
}
