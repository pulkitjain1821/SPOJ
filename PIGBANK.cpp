#include <cstdio>
#include <cstdlib>
#define inf 1000000000
using namespace std;

void display(int values[],int weights[], int count)
{
  for(int i=0;i<count;i++)
		{
			printf("Values of coin: %d, weight: %d \n",values[i],weights[i]);
		}
}
void min_money(int n, int vals[], int weights[], int count)
{
	int arr[n+1];
	for(int i=0;i<n+1;i++)
		{
			arr[i] = inf;
		}
	arr[0] = 0;
	for(int i=1;i<n+1;i++)
	{
		int min = inf;
		for(int j=0;j<count;j++)
		{
			if(i-weights[j]>=0)
				{
					if(vals[j] + arr[i-weights[j]] < min)
						min = vals[j] + arr[i-weights[j]];
				}
		}
		arr[i] = min;
	}
	if(arr[n]!=inf)
		printf("The minimum amount of money in the piggy-bank is %d.\n",arr[n]);
	else
		printf("This is impossible.\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	//printf("Accepted value %d\n",t);
	while(t>0)
		{
			t--;
			int e;
			int f;
			scanf("%d%d",&e,&f);
			//printf("Weight of empty = %d, filled = %d\n",e,f);
			if(e==f)
				{
					printf("The minimum amount of money in the piggy-bank is 0.\n");	
					continue;
				}
			int n;
			scanf("%d",&n);
			//printf("Number of denominations is %d\n",n);
			int v[n];
			int w[n];
			int i=0;
			while(i<n)
			{
				scanf("%d%d",v+i,w+i);
				i++;
			}
			//display(v,w,n);
			min_money(f-e,v,w,n);
		}
	return 0;
}
