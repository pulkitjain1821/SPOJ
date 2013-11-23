#include<cstdio>
#include<cstdlib>
#include<queue>
#define inf 1000000001
using namespace std;
typedef struct edge
{
	int v;
	int w;
}edge;

int readInt() 
{
	bool minus = false;
	int result = 0;
	char ch;
	//ch = getchar_unlocked();
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
		//ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		//ch = getchar_unlocked();
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


bool operator <(edge a, edge b)
{
	return a.w < b.w;
}

int main()
{
	int x,n,m,s,t;
	//int a,b,w;
	//scanf("%d",&x);
	x = readInt();
	for(int l=0;l<x;l++)
	{
		//scanf("%d%d%d%d",&n,&m,&s,&t);
		n = readInt();
		m = readInt();
		s = readInt();
		t = readInt();
		
		vector<edge> adj[n];// = (vector<edge>*)malloc(n*sizeof(vector<edge>));
		int *dist = (int*)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
		{
			dist[i] = inf;
		}
		//printf("Here!!\n");
		for(int i=0;i<m;i++)
		{
			edge *a1,*a2;
			a1 = (edge*)malloc(sizeof(edge));
			a2 = (edge*)malloc(sizeof(edge));
			//scanf("%d%d%d",&a,&b,&w);
			//a = readInt();
			//b = readInt();
			//w = rea
			
			a1->v = readInt()-1;
			a2->v = readInt()-1;
			a1->w = a2->w = readInt();
			adj[a1->v].push_back(*a2);
			adj[a2->v].push_back(*a1);
		}
		priority_queue<edge> mine;
		edge temp;
		temp.v = s-1;
		temp.w = 0;
		mine.push(temp);
		dist[s-1] = 0;
		while(!mine.empty())
		{
			edge top = mine.top();
			mine.pop();
			for(int k=0;k<adj[top.v].size();k++)
			{
				if(dist[top.v] + adj[top.v][k].w < dist[adj[top.v][k].v])
				{
					dist[adj[top.v][k].v] = dist[top.v] + adj[top.v][k].w;
					mine.push(adj[top.v][k]);
				}
			}
		}
		if(dist[t-1]<inf)
		{
			printf("%d\n",dist[t-1]);
		}
		else
			printf("NONE\n");

		free(dist);
		//free(adj);
		//free(status);
	}	
	return 0;
}
