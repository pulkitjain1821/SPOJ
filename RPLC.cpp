#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

void display(long long int arr[], int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%lld ",arr[i]);
	}	
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		long long int* arr = new long long int[n];
		long long int* sum = new long long int[n];
		//printf("Here!!");
		for(int j=0;j<n;j++)
		{
			scanf("%lld",arr+j);
		}
		//display(arr,n);
		//printf("Here!!");
		sum[0] = arr[0];
		long long int min = sum[0];
		for(int j=1;j<n;j++)
		{
			sum[j] = sum[j-1] + arr[j];
			//printf("sum[j] = %lld, sum[j-1] = %lld, arr[j] = %lld\n",sum[j],sum[j-1],arr[j]);
			if(sum[j] < min)
			{
			//	printf("Changing min now\n");
				min = sum[j];
			}
			
		}
		//display(sum,n);
		//display(arr,n);
		//printf("%lld is min found\n",min);
		
		if(min <=0)
			min =  min*(-1) + 1;
		else
			min = 1;	
		//printf("Here!!");
		printf("Scenario #%d: %lld\n",i+1,min);
	}
	return 0;
}
