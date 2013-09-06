#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int big, int small)
{
	if(big%small ==0)
		return small;
	else
		return gcd(small,big%small);	
}

int getRem(char* arr, int len, int a)
{
	int digits = ceil(log10(a));
	int temp = 0;
	int i;
	for(i=0;i<digits && i<len;i++)
	{
		temp = temp*10 + arr[i]-'0';
	}
	temp = temp%a;
	while(i<len)
	{
		temp = temp*10 + arr[i]-'0';
		temp = temp%a;
		i++;
	}
	return temp;
}

int main()
{
	int t;
	scanf("%d",&t);
	char arr[251];
	int a,b,len;
	char c;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a);
		getchar();
		len=0;
		while((c=getchar())!='\n'&&c!=EOF)
		{
			arr[len++]=c;
		}
		arr[len]='\0';
		if(a==0)
		{
			printf("%s\n",arr);
		}
		else
		{
			int b = getRem(arr,len,a);
			if(b==0)
				printf("%d\n",a);
			else
				printf("%d\n",gcd(a,b));
		}
	}
	return 0;
}
