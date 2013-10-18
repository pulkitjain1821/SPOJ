#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int *arr = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	int count = 0;
	int search = n;
	int i = n-1;
	while(i>=0 && search >0)
	{
		if(arr[i]==search)
		{
			search--;
		}
		else
		{
			count++;
		}
		i--;
	}
	printf("%d\n",count);
	return 0;
}
