#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

long long int gcd(long long int small,long long int big)
{
	if(big%small==0)
	{
		return small;
	}
	return gcd(big%small,small);
}

long long int lcm(long long int arr[], char str[])
{
	long long int ans;
	/*for(int i=1;i<=arr[0];i++)
	{
		printf("%d--\n",arr[i]);
	}
	printf("%s\n",str);
	*/
	
	if(arr[0]==0)
		return -1;
	else if(arr[0]==1)
	{
		ans = arr[1];
	}
	else
	{
	
		ans = (arr[1]*arr[2])/(gcd(min(arr[1],arr[2]),max(arr[1],arr[2])));
		for(int i=3;i<=arr[0];i++)
		{
			ans = (ans*arr[i])/(gcd(min(ans,arr[i]),max(ans,arr[i])));
		}
		//printf("ans is %d\n",ans);
	}
	for(int i=0;i<strlen(str);i++)
	{
		//printf("here!!\n");
		if(str[i]=='Y')
		{
		//	printf("This is a Y");
			if(ans%(i+1)!=0)
				return -1;
		}
		else
		{
		//	printf("This is a N");
			if(ans%(i+1)==0)
				return -1;
		}
	}
	return ans;
}

int main()
{
	char str[21];
	long long int arr[21];
	while(true)
	{
		scanf("%s",str);
		if(str[0]=='*')
			break;
		int l = strlen(str);
		arr[0] = 0;
		for(int i=0;i<l;i++)
		{
			if(str[i]=='Y')
			{
				arr[++arr[0]] = i+1;
			}
		}
		printf("%lld\n",lcm(arr,str));
	}
		
	return 0;
}
