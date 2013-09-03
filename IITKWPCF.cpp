#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<list>
using namespace std;
long long int primes[100000];
bool isPrime[1000001];
int len = 0;
long long int Max;
	
bool isprime(long long int x)
{
	if(x==1)
		return 0;
	if(x==2 || x==3)
		return 1;
	for(int i =0;primes[i]<=sqrt(x);i++)
	{
		if(x%primes[i] ==0)
			return 0;
	}
	return 1;
} 

bool isprime2(long long int x)
{
	if(x <= Max)
	{
		return isPrime[x];
	}
	else
	{
		return isprime(x);
	}	
}

void genprimes(long long int max)
{
	Max = sqrt(max);
	int j;
	for(int i=0;i<=Max;i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	
	for(int i =2;i<=Max;i++)
	{
		if(isPrime[i])
		{
			for(j= 2*i;j<=Max;j+= i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	/*for(int i=0;i<=sqrt(max);i++)
	{
		printf("%d is prime %d\n",i,isPrime[i]);
	}*/
	for(int i=0;i<=sqrt(max);i++)
	{
		if(isPrime[i])
		{
			primes[len++] = i;
		}
	}
}

void factors(long long int n)
{
	list<long long int> smalls;
	list<long long int> bigs;
	for(long long int i=1;i<=sqrt((double)n);i++)
	{
		if(n%i==0)
		{
			if(n/i != i)
			{
				if(!isprime2(i))
					{
						//printf("%d is a non prime factor\n",i);
						smalls.push_back(i);
					}
				if(!isprime2(n/i))
					{
						//printf("%d is a non prime factor\n",n/i);
						bigs.push_front(n/i);
					}
			}
			else
			{
					//printf("%d is a non prime factor\n",i);
					if(!isprime2(i))
						smalls.push_back(i);
			}
		}
	}
	printf("%d ",smalls.size()+bigs.size());
	for(list<long long int>::iterator it = smalls.begin();it!=smalls.end();it++)
	{
		printf("%lld ",*it);
	}

	for(list<long long int>::iterator it = bigs.begin();it!=bigs.end();it++)
	{
		printf("%lld ",*it);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	long long int arr[t];
	long long int max = 0;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",arr+i);
		if(max < arr[i])
			max = arr[i];
	}

	genprimes(max);
	
	for(int i=0;i<t;i++)
	{
		if(arr[i]%2!=0)
			printf("0\n");
		else
			factors(arr[i]/2);
	}
	/*int knownPrimes[100000];
	int n; int count = 0;
	scanf("%d",&n);
	while(n<1000000)
	{
		knownPrimes[count++] = n;
		scanf("%d",&n);
	}

	if(len==count)
	{
		for(int i=0;i<len;i++)
		{
			if(knownPrimes[i]!=primes[i])
				printf("Wrong at i: %d\n",i);
		}
	}
	else
	{
		printf("len mismatch\n");
	}
	*/

}
