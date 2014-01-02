#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define mod 1000000009
using namespace std;
int arr[50000];

long long int pow(long long int a, int b)
{
	a = a%mod;
	if(b==0)
		return 1;
	long long int temp = (a*a)%mod;
	if(b%2==0)
		return pow(temp,b/2);
	else
		return (a*pow(temp,b/2))%mod;
}

int readInt () 
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}



int main()
{
	int i,t,n;
	//scanf("%d",&t);
	t = readInt();
	for(int l=0;l<t;l++)
	{
		long long int zcount = 0,count = 0, ans = 0;
		//scanf("%d",&n);
		n  = readInt();
		for(i=0;i<n;i++)
		{
			//scanf("%d",arr+i);
			arr[i] = readInt();
			if(arr[i]==0)
			{
				zcount++;	
			}
		}
		sort(arr,arr+n);
		i--;
		while(i>=0 && arr[i]>0)
		{
			ans += arr[i--];
		}
		if(ans > 0)
		{
			count = pow(2,zcount);
		}
		else 
		{
			if(arr[n-1]<0)
			{
				ans = arr[n-1];
				int j = n-1;
				while(j>=0 && arr[j]==arr[n-1]) 
				{
					count++;
					j--;
				}	
			}
			else
			{
				ans = 0;
				count = pow(2,zcount)-1;
			}
		}	
		printf("%lld %d\n",ans,count);
	}
	return 0;
}
