#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	char arr[4];
	scanf("%d",&n);
	int one = 0, two = 0, three = 0, ans = 0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",arr);
		if(strcmp(arr,"1/4")==0)
			one++;
		if(strcmp(arr,"1/2")==0)
			two++;
		if(strcmp(arr,"3/4")==0)
			three++;		
	}
	
	if(three < one)
	{
		ans += three;
		one -= three;
		three = 0;
	}
	else
	{
		ans += one;
		three -= one;
		one = 0;
	}
	
	ans += three;
	ans += one/4;
	one = one%4;
	
	ans += two/2;
	two = two%2;
	
	if(!two)
	{
		if(one)
			ans++;
	}
	else
	{
		if(one>=3)
		{
			ans+=2;
		}
		else
			ans++;	
	}
	
	/*if(one%4 !=0)
	{
		ans += 1;
	}
	
	ans += two/2;
	if(two%2!=0)
	{
		ans+= 1;
	} */
	printf("%d\n",ans+1);
	return 0;
}
