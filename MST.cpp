#include<cstdlib>
#include<cstdio>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;

typedef struct
{
	int node1;
	int node2;
	int weight;
} Edge;

bool sortEdge(const Edge &edge1, const Edge &edge2)
{
	return edge1.weight < edge2.weight;
}
void insert(int* nodes, int len, long long int* sum, int* count,int * count_counts, Edge ed)
{
	if(nodes[ed.node1]==-1 && nodes[ed.node2]==-1)
	{
		(*count)= (*count) + 1;
		nodes[ed.node1] = *count;
		nodes[ed.node2] = *count;
		count_counts[(*count)]++;
		count_counts[(*count)]++;
		(*sum) = (*sum) + ed.weight;
	}
	else if(nodes[ed.node1]!=-1 && nodes[ed.node2]==-1)
	{
		nodes[ed.node2] = nodes[ed.node1];
		count_counts[nodes[ed.node2]]++;
		(*sum) = (*sum) + ed.weight;
	}
	else if(nodes[ed.node2]!=-1 && nodes[ed.node1]==-1)
	{
		nodes[ed.node1] = nodes[ed.node2];
		count_counts[nodes[ed.node1]]++;
		(*sum) = (*sum) + ed.weight;
	}
	else
	{
		if(nodes[ed.node1]!=nodes[ed.node2])
		{
			int final = count_counts[nodes[ed.node1]] >= count_counts[nodes[ed.node2]]? nodes[ed.node1]:nodes[ed.node2];
			int tobechanged = count_counts[nodes[ed.node1]] < count_counts[nodes[ed.node2]]? nodes[ed.node1]:nodes[ed.node2];	
			(*sum) = (*sum) + ed.weight;
		
			for(int i=0;i<len;i++)
			{
				if(nodes[i]==tobechanged)
				{
					nodes[i] = final;
					count_counts[final]++;
					count_counts[tobechanged]--;
				}
			}
		}		
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int count = -1;
	int * nodes = (int*)malloc(n*sizeof(int));
	int *count_counts = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		nodes[i] = -1;
		count_counts[i] = 0;
	}
	
	Edge* arr = (Edge*)malloc(m*sizeof(Edge));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&(arr[i].node1),&(arr[i].node2),&(arr[i].weight));		
		arr[i].node1--;
		arr[i].node2--;
	}
	sort(arr,arr+m,sortEdge);
	
	//printf("hello!!!\n");
	long long int sum = 0;
	for(int i=0;i<m;i++)
	{
		//printf("Inserted\n");
		insert(nodes,n,&sum,&count,count_counts,arr[i]);
	}
	printf("%lld\n",sum);
	return 0;
}
