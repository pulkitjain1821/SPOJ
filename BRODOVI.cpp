#include<cstdio>
#include<cstdlib>
using namespace std;
int binsearch(int x,int arr[], int start,int len)
{
	int lower = start;
	int upper = len-1;
	int mid;
	while(upper>=lower)
	{
		mid = (upper+lower)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid] < x)
		{
			lower = mid+1;
		}
		else
		{
			upper = mid-1;
		}
	}
	return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[5000] = {0};
	int status[5000] = {0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	int count = 0;
	for(int i=1;i<n;i++)
	{
		if(status[i]==0)
		{
			count++;
			int d = arr[i] - 1;
			int next  = i;
			while(1)
			{
				int ind = binsearch(arr[next] + d,arr,next+1,n);
				if(ind >0 && ind<n)
				{
					status[ind] = count;
					next = ind;
				}
				else
				{
					break;
				}
			}
		}	
	}
	if(count>=1)
		printf("%d\n",count);	
	else
		printf("1\n");
	return 0;
}
