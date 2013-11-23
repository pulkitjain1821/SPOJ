#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	long long int T[50];
	long long int K[50];
	K[0] = 0;
	T[0] = T[1] = K[1] = 1;
	T[2] = 5;
	T[3] = 11;
	
	for(int i=4;i<=49;i++)
	{
		K[i-2] = T[i-3] + K[i-4];
		T[i] = 2*T[i-1] + 3*T[i-2] - T[i-3] + K[i-3] - K[i-2];
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int temp;
		scanf("%d",&temp);
		printf("%d %lld\n",i+1,T[temp]);
	}
	return 0;
}

