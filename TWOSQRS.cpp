#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
long long int sqr[1000001];

bool isSqr(long long int x)
{
	int ptr1 = 0;
	int ptr2 = (int)sqrt(x) + 1;
	long long int sum;
	while(ptr1<=ptr2)
	{
		sum = sqr[ptr1]+sqr[ptr2];
		if(sqr[ptr1]+sqr[ptr2]==x)
			return true;
		else if(sum > x)
		{
			ptr2--;
		}
		else 
		{
			ptr1++;
		}
	}
	return false;
}

int main()
{
	for(long long int i=0;i<=1000000;i++)
	{
		sqr[i] = i*i;
	}
	
	int t;
	scanf("%d",&t);
	long long int num;
	for(int i =0;i<t;i++)
	{
		scanf("%lld",&num);
		if(isSqr(num))
		{
			printf("Yes\n");	
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
