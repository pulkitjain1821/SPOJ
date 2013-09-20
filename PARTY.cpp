#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
	while(true)
	{
		int amt,n;
		scanf("%d%d",&amt,&n);
		if(n==0&&amt==0)
			break;
		int fee[n];
		int fun[n];
		//printf("Budget = %d, parties = %d\n",amt,n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",fee+i,fun+i);
			//printf("%d %d\n",fee[i],fun[i]);
		}
		//printf("-\n");
		bool inc[amt+1][n];
		for(int i=0;i<=amt;i++)
		{
			for(int j=0;j<n;j++)
			{
				inc[i][j] = 0;
			}
		}
	
	
		int max_fun[amt+1];
		int cost_fun[amt+1];
		for(int i=0;i<=amt;i++)
		{
			max_fun[i] = cost_fun[i] = 0;
		}

		for(int k= 1;k<=amt;k++)
		{
			int max = max_fun[k-1];
			int cost = cost_fun[k-1];
			int curr,prev;
			for(int i=0;i<n;i++)
			{
				if(k-fee[i]>=0 && inc[k-fee[i]][i]==0)
				{
					int tfun = max_fun[k-fee[i]] + fun[i];
					int tcost = cost_fun[k-fee[i]] + fee[i];
					if(tfun>max)
						{
							max = tfun;
							curr = i;
							prev = k-fee[i];
							cost = tcost;
						}
					else if(tfun==max && tcost<cost)
					{
							max = tfun;
							curr = i;
							prev = k-fee[i];
							cost = tcost;						
					}
				}
			}
			if(max > 0)
			{
				max_fun[k] = max;
				cost_fun[k] = cost;
				for(int z=0;z<n;z++)
				{
					inc[k][z] = inc[prev][z];
				}
				inc[k][curr] = 1;
			}
			//printf("k -(%d,%d)\n",cost_fun[k],max_fun[k]);
		}
		/*int cost = 0;
		for(int i=0;i<n;i++)		
		{
			cost += inc[amt][i] * fee[i];
		}*/
		printf("%d %d\n",cost_fun[amt],max_fun[amt]);
		/*for(int i=0;i<n;i++)
		{
			//printf("Checking if ith party included\n");
			if(inc[amt][i]==1)
			{
				printf("Party %d with fee = %d, fun = %d\n",i,fee[i],fun[i]);
			}
		}*/
	}
	return 0;
}
