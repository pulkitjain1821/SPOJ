#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
		{
			t--;
			int ng;int mg;
			scanf("%d%d",&ng,&mg);
			int ngmax=0;
			int mgmax=0;
			int tmp;
			for(int i=0;i<ng;i++)
				{
					scanf("%d",&tmp);
					if(ngmax<tmp)
						ngmax=tmp;
				}
			for(int i=0;i<mg;i++)
				{
					scanf("%d",&tmp);
					if(mgmax<tmp)
						mgmax=tmp;
				}	
			if(ngmax>=mgmax)
				printf("Godzilla\n");
			else
				printf("MechaGodzilla\n");
					
		}
	return 0;
}
