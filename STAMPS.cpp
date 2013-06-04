#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
  int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int arr[1000];
		int borrow;
		int n_friends;
		scanf("%d%d",&borrow,&n_friends);
		int num = n_friends;
		while(n_friends>0)
		{
			scanf("%d",&arr[--n_friends]);
		}
		sort(arr,arr+num);
	
		int sum =0;
		int num2 =  num;
		while(sum < borrow && num>=0)
		{
			sum += arr[--num];
		}
		printf("Scenario #%d:\n",i+1);
		if(sum>=borrow)
			printf("%d\n",num2-num);
		else
			printf("impossible\n");
	}
	return 0;
}
