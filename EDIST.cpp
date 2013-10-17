#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ans[2001][2001];
int edit(char* arr, char* brr)
{
	int la = strlen(arr);
	int lb = strlen(brr);
	for(int i=0;i<=la;i++)
	{
		ans[i][0] = i;
	}
	for(int i=0;i<=lb;i++)
	{
		ans[0][i] = i;
	}

	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			if(arr[i-1]==brr[j-1])
			{
				ans[i][j] = ans[i-1][j-1];
			}
			else
			{
				ans[i][j] = min(min(1+ans[i-1][j],1+ans[i-1][j-1]),1+ans[i][j-1]);
			}
		}
	}
	/*
	int lcs = ans[la][lb];
	return abs(lcs - lb);
	*/
	return ans[la][lb];
}

int main()
{
	char arr[2001];
	char brr[2001];
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",arr);
		scanf("%s",brr);
		printf("%d\n",edit(arr,brr));
	}
	return 0;
}
