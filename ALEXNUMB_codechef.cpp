#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
int main()
{
	int t,n,num;
	scanf("%d",&t);
	for(int l=0;l<t;l++)
	{
		scanf("%d",&n);
		map<int,bool> mine; 
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			mine[num] = true;
		}
		long long int res = mine.size();
		printf("%lld\n",res*(res-1)/2);
	}
	return 0;
} 
