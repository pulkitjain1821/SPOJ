#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		int w,b;
		scanf("%d%d",&w,&b);
		printf("%.6f\n",(double)(b%2));	
	}
	return 0;
}
