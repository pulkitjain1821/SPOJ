#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int Primes[78500]; int iter = 0;
	Primes[iter++] = 2;
	bool* isPrime = (bool*)malloc(500001*sizeof(bool)) ;
	for(int i=0;i<=500000;i++)
	{
		isPrime[i] = true;
	}
	
	isPrime[0] = false;
	for(long long int i=3;i*i<=1000000;i+=2)
	{
		if(isPrime[i/2])
		{
			for(int j=i*i;j<=1000000;j+=2*i)
			{
				isPrime[j/2] = false;
			}
		}
	}
	for(int i=0;i<=500000;i++)
	{
		if(isPrime[i])
		Primes[iter++] = 2*i + 1;
	}
	/*for(int i=78398;i<=78497;i++)
	printf("%d\n",Primes[i]);
	*/
	/*int count = 0;
	for(int i=0;i<=1000000;i++)
	if(isPrime[i]) count++;
	
	printf("%d\n",count);
	/**/
	int t;
	long long int l,r;
	scanf("%d",&t);
	//printf("Here!!!!\n");
	int* temp[2];
	*temp = (int*)malloc(1000001*sizeof(int));
	*(temp+1) = (int*)malloc(1000001*sizeof(int));
	
	//printf("Here!!!!\n");

	for(int j=0;j<t;j++)
	{
		int ans = 0;
		scanf("%lld%lld",&l,&r);
		for(long long int i=0;i<=r-l;i++)
		{
			temp[0][i]= 0;
		}
		//printf("Hmmmm!!\m");
		for(long long int i=0;Primes[i]*(long long int)Primes[i]<=r  && i<iter;i++)
		{
			long long int start = ((l + Primes[i] - 1)/Primes[i])*Primes[i] - l;
			for(;start<=r-l;start+=Primes[i])
			{
				temp[0][start]++;
				temp[1][start] = Primes[i];
			}	
		}
		//printf("Hehehhehe!!!\n");
		for(long long int i=0;i<=r-l;i++)
		{
			if(temp[0][i]==0 && (i+l != 1))
				ans++;
			if(temp[0][i]==1)
			{
				int count = 1;
				long long int num = i+l;
				while(num%temp[1][i]==0)
				{
					count++;
					num /= temp[1][i];
				}
				if(num==1)
				{
					if(count==2)
					{
						ans++;
					}
					else if(count%2!=0)				
					{
						if(isPrime[count/2])
							ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
