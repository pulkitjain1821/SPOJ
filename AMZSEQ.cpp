#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	unsigned int arr[50][3];
	arr[0][0] = arr[0][1] = arr[0][2] = 0;
	arr[1][0] = arr[1][1] = arr[1][2] = 1;
	for(int l=2;l<50;l++)
	{
		arr[l][0] = arr[l-1][0] + arr[l-1][1];
		arr[l][1] = arr[l-1][0] + arr[l-1][1] + arr[l-1][2];
		arr[l][2] = arr[l-1][1] + arr[l-1][2];
	}
	int n;
	scanf("%d",&n);
	printf("%u\n",arr[n][0] + arr[n][1] + arr[n][2]);
	return 0;
}
