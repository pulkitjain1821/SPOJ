#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

void display(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int search(int x, int sorted[], int len)
{
	int lower = 0;
	int upper = len-1;
	int mid;
	while(lower<=upper)
	{
		mid = (lower+upper)/2;
		if(sorted[mid]==x)
			return mid;
		else if(x< sorted[mid])
		{
			upper = mid-1;		
		}
		else
		{
			lower = mid + 1;
		}
	}
	return 0;
}

void modify (int arr[], int sorted[], int len)
{
	/*display(arr,len);
	printf("before modifying\n");
	*/
	sort(sorted,sorted+len);
	for(int i=0;i<len;i++)
	{
		int temp = arr[i];
		int res =  search(temp,sorted,len) + 1;
		//printf("Index of %d in sorted is %d\n",temp,res-1);
		arr[i] = res;
	}	

	/*printf("Sorted array is\n");
	display(sorted,len);
	printf("Modified array is\n");
	display(arr,len);
	*/
}

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		int arr[n];
		int sorted[n];
		
		int j;
		for(j=0;j<n;j++)
		{
			scanf("%d",a+j);
			sorted[j] = a[j];
		}
		/*printf("-----\n");
		display(arr,n);
		display(sorted,n);
		printf("-----\n");
		*/
		modify(a,sorted,n);
		for(j=0;j<n;j++)
		{
			arr[a[j]-1] = j;
		}
		
		
		
		int max = 0;
		j=0;
		//printf("Accepted input\n");
		while(j<n-1)
		{
			int temp =1;
			while(arr[j]<arr[j+1] && j+1<n)
			{
				temp++;
				j++;
			}
			if(temp>max)
			{
				max = temp;
			}
			j++;
		}
		printf("%d\n",n-max);
	
	}
	return 0;
}
