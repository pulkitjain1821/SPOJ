// Read from wiki


#include<cstdio>
#include<cstdlib>
using namespace std;
int arr[1000001];

int main()
{
	int n,d;
	while(true)
	{
		scanf("%d%d",&n,&d);
		if(n==0&&d==0)
			break;
		arr[0] = -1;
		arr[1] = 1;
		for(int i=2;i<=n;i++)
		{
			arr[i] = (arr[i-1] + d-1)%i + 1;
		}
		printf("%d %d %d\n",n,d,arr[n]);
	}
	return 0;
}
