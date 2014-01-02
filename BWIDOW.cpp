#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct
{
	int inner;
	int outer;
	int index;
}Ring;

Ring arr[1000];

bool outer(const Ring& a, const Ring &b)
{
	return a.outer < b.outer;
}
bool inner(const Ring& a, const Ring &b)
{
	return a.inner < b.inner;
}

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&(arr[i].inner),&(arr[i].outer));
			arr[i].index = i+1;
		}
		sort(arr,arr+n,inner);
		int maxi = arr[n-1].inner;
		int ind = arr[n-1].index;
		sort(arr,arr+n-1,outer);
		if(arr[n-2].outer < maxi)
		{
			printf("%d\n",ind);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
