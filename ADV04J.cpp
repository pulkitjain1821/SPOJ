#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[1000001];
int main()
{
	arr[3] = arr[4] = 3;
	arr[5] = 4;
	for(int i=6;i<=1000000;i++)
	{
		if(i&1)
		{
			arr[i] = 1 + max(arr[i/2],arr[i/2 +1]);
		}
		else
		{
			arr[i] = 1+arr[i/2];
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}
	return 0;
}
