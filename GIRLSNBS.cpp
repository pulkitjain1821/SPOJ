#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
  while(1)
	{
			int x;
			int y;
			scanf("%d%d",&x,&y);
			if(x==-1 && y==-1)
				break;
			if(x==0)
				printf("%d\n",y);
			else if(y==0)
				printf("%d\n",x);
			else
				{
					int max,min;
					if(x>y)
						{
							max = x;
							min = y;
						}
					else
						{
							max = y;
							min = x;
						}
					printf("%d\n",(int)ceil((double)max/(min+1)));
				}
	}
	return 0;
}
