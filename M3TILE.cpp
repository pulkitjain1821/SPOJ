/*

http://stackoverflow.com/questions/16388579/spoj-m3tile-solution-explanation

*/




#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	long long int ans[31];
	ans[0] = 1;
	ans[1] = 0;
	ans[2] = 3;
	ans[3] = 0;
	for(int i=4;i<31;i++)
	{
		ans[i] = 4*ans[i-2] - ans[i-4];
	}
	int num;
	while(true)
	{
		scanf("%d",&num);
		if(num==-1)
			break;
		printf("%lld\n",ans[num]);
	}
	return 0;
}
