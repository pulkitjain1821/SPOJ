#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n,r;
	while(true)
	{
		scanf("%d%d",&n,&r);
		if(n==0 && r==0)
			break;
		int amt[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",amt+i);
		}
		int rec_max[r];
		for(int i = 0;i<r;i++)
		{
			int min = 100000000;
			for(int j = 0;j<n;j++)
			{
				int rec;
				scanf("%d",&rec);
				if(rec!=0)
				{
					if(min > (amt[j]*10)/rec)
						min = (amt[j]*10)/rec;
				}
			}
			rec_max[i] = min;
		}
		
		int maxind = -1;
		int max = -1;
		for(int i = 0;i<r;i++)
		{
			if(max < rec_max[i])
			{
				max = rec_max[i];
				maxind = i;
			}
		}	
		printf("%d %d\n",maxind+1,max);
	}
	return 0;
}
