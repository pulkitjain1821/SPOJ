#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int* bfs(int s,vector<int> adj[],int n)
{
		//printf("bfs with source as %d\n",s);
		int ans[2]={0,0};
		int status[n];
		int d[n];
		for(int m=0;m<n;m++)
			status[m]=d[m]=0;
			
		queue<int> Q;
		Q.push(s);
		status[s]=1;
		while(!Q.empty())
			{
				int u = Q.front();
				for (int k=0;k<adj[u].size();k++)		
					{
						if(status[adj[u][k]]==0)
							{
								Q.push(adj[u][k]);
								status[adj[u][k]]=1;
								d[adj[u][k]]=d[u]+1;
								if(ans[0]<d[adj[u][k]])
									{
										ans[1]=adj[u][k];
										ans[0]=d[adj[u][k]];
									}
							}
					}
				status[u]=2;
				Q.pop();
			}
		//printf("maximum path length from this as source was %d\n",max);
		return ans;
}
	
int main()
{
	//printf("Getting started--\n");
	
	
	int n;
	scanf("%d",&n);
	std::vector<int> adj[n];
	int degree[n];
	for(int i=0;i<n;i++)
		degree[i]=0;
	n;
	//printf("Tree of size %d--\n",n);
	int x=0;
	while(x<n-1)
		{
			//printf("While getting started--\n");
			x++;
			int u,v;
			scanf("%d%d",&u,&v);
			degree[u-1]++;
			degree[v-1]++;
			//printf("Degree updated--\n");
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
			//printf("While last--\n");
		}
	//printf("While over--\n");
/*
	printf("----------------------------------------------------------\n");
	for(int z=0;z<n;z++)
		{
			printf("%d-> ",z);
			for(int l=0;l<adj[z].size();l++)
				printf("%d ",adj[z][l]);
			printf("\n");
		}		
	printf("----------------------------------------------------------\n");
			
  	for(int i=0;i<n;i++)
		printf("Degree of vertex %d is %d\n",i,degree[i]);
*/	
	int max=0;
	 int * a = bfs(0,adj,n);
	 int ans = *(bfs(*(a+1),adj,n));
	printf("%d\n",ans);
	return 0;
}
