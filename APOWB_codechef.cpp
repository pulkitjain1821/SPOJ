/*  approach refered from http://stackoverflow.com/a/10215614/1291575 */


#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
 
long long int mypow(long long int a, int b)
{
	if(b==0)
		return 1;
	long long int temp = a*a;
	if(b%2==0)
		return mypow(temp,b/2);
	return a*mypow(temp,b/2);
}
 
bool exists(long long int n,int b)
{
	double cand = pow(n,1/(double)b);
	long long int c1 = cand;
	if(mypow(c1,b)==n || mypow(c1+1,b)==n)
		return true;
	return false;
}
 
int main()
{
	int t;
	long long int n;
	scanf("%d",&t);
	//printf("T recieved was %d\n",t);
	for(int l=0;l<t;l++)
	{
	//	printf("%d inputs remaining\n",t-l);
		scanf("%lld",&n);
	//	printf("N recieved was %d\n",n);
		int lim = log(n)/log(2) + 1;
		bool done = false;
		for(int i = lim;i>=2;i--)
		{
			if(exists(n,i))
			{
				printf("YES\n");
				done = true;
				break;
			}
		}
		if(!done)
		{
			printf("NO\n");
		}
	}
	//printf("DOne\n");
	return 0;
} 
