#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct 
{
	long long int sum;
	int index;	
}ele;

bool sorting (ele a, ele b)
{
	return (a.sum == b.sum ? a.index < b.index : a.sum < b.sum);
}

int main()
{
	long long int t,temp;
	scanf("%lld",&t);
	long long int n;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		ele* arr = (ele*)malloc((n+1)*sizeof(ele));
		scanf("%lld",&temp);
		arr[0].sum = 0;
		arr[0].index = -1;
		arr[1].sum = temp;
		arr[1].index = 0;
		for(int j=1;j<n;j++)
		{
			scanf("%lld",&temp);
			arr[j+1].sum = arr[j].sum + temp;
			arr[j+1].index = j;
		}
		/*
		for(int i=0;i<n+1;i++)
		{
			printf("%d ",arr[i].sum);
		}
		printf("\n******\n");
		*/
		sort(arr,arr+n+1,sorting);
		/*
		for(int i=0;i<n+1;i++)
		{
			printf("%d ",arr[i].sum);
		}*/
		//printf("\n");
		int temp1;
		int ans = 0;
		for(int j=0,k=0;j<n+1 && k<n+1;)
		{
			if(arr[k].sum - arr[j].sum == 47)
			{
				temp1 = k;
				while(arr[temp1].sum==arr[k].sum)
				{
					if(arr[temp1].index > arr[j].index)
						ans++;
					temp1++;
				}
				j++;
			}
			else if (arr[k].sum - arr[j].sum > 47)
			{
				j++;
			}
			else
			{
				k++;
			}
		}
		printf("%d\n",ans);
		free(arr);
	}
	return 0;
}
