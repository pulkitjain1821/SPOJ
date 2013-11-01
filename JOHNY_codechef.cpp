#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t,n,k;
	scanf("%d",&t);
	int arr[100];
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",arr+j);
		}
		scanf("%d",&k);
		k = arr[k-1];
		int count = 0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]<k)
			count++;
		}
		printf("%d\n",count+1);
	}
	return 0;
}
