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
		int n,s;
		scanf("%d%d",&n,&s);
		if(s==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;
}
