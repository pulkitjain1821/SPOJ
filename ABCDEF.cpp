#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n,iter1,iter2;
	scanf("%d",&n);
	int* comb = (int*)malloc((n*n*n)*sizeof(int));
	int* sum = (int*)malloc((n*n*n)*sizeof(int));
	int* arr = (int*)malloc(n*sizeof(int));
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	
	iter1 = iter2 = 0;
	for(int i=0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				comb[iter1++] = arr[i]*arr[j] + arr[k];
				if(arr[k])
					sum[iter2++] = (arr[i]+arr[j]) * arr[k];
			}
		}
	}
	sort(comb,comb+iter1);
	sort(sum,sum+iter2);
	long long int ans = 0;
	
	for(int i=0,j=0;i<iter1 && j<iter2;)
	{
		if(sum[j] == comb[i])
		{
			int temp = j;
			while(sum[temp]==sum[j])
				temp++;
			ans += temp - j;
			i++;
		}
		else if(sum[j] < comb[i])
			j++;
		else
			i++;
	}
	printf("%lld\n",ans);
	return 0;
}
