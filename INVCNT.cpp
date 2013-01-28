#include <cstdio>
using namespace std;
long long int inversions(int a[],int s,int e)
{
	
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
		{
			t--;
			int n;
			scanf("%d",&n);
			int a[n];
			for(int i=0;i<n;i++)
				scanf("%d",&a[i]);
			printf("%lld\n",inversion(arr,0,n));
		}
	return 0;
}
