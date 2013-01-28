#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(y==x)
				{
					if(x&1)
						printf("%d\n",2*x -1);
					else
						printf("%d\n",2*x);
				}
			else if (y==x-2)
				{
					if(x&1)
						printf("%d\n",2*x-3);
					else
						printf("%d\n",2*(x-1));
				}
			else
					printf("No Number\n");
		}
	return 0;
}

