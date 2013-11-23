/*
Storing number of factors for all proves slower than calculting on the fly for GCDs of every pair
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
//int arr[1000001];
using namespace std;
int readInt () 
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	//ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
		//ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		//ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int gcd(int mini,int maxi)
{
	if(maxi % mini==0)
		return mini;
	else
		return gcd(maxi%mini,mini);
}

int numfac(int n)
{
	int res = 0;
	long long int i;
	for(i=1;i*i<n;i++)
	{
		if(n%i==0)
			res +=2;
	}
	if(i*i==n)
		res++;
	return res;
}

int main()
{
	/*for(int i=0;i<=1000000;i++)
	{
		arr[i] = 2; 
	}
	arr[1] = 1;
	
	for(long long int i=2;i<=1000000;i++)
	{
		if(i*i <= 1000000)
		arr[i*i]++;	
		for(long long int j=i*i + i;j<=1000000;j+=i)
		{
			arr[j]+= 2;
		}
	}*/
	int t,a,b;
	t = readInt();
	//scanf("%d\n",&t);
	for(int i=0;i<t;i++)
	{
		//scanf("%d%d",&a,&b);
		a = readInt();
		b = readInt();
		//printf("%d\n",arr[gcd(min(a,b),max(a,b))]);
		printf("%d\n",numfac(gcd(min(a,b),max(a,b))));
	}
	return 0;
}
