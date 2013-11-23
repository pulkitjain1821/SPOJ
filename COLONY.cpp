#include<cstdio>
#include<cstdlib>
using namespace std;

int getVal(int y, long long int p, int invert)
{
	if(0==y)
	{
		int ans = (invert^1);
		return ans ;
	}
	else
	{
		return getVal(y-1,p/2,((p+1)&1)^invert);
	}
}

int main()
{
	int y;
	long long int p;
	scanf("%d%lld",&y,&p);
	int ans = getVal(y,p,0);
	if(ans)
		printf("red");
	else
		printf("blue");
	return 0;
}
