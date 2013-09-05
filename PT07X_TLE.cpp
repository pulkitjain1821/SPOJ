#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
int vertexCover(vector<int>arr[], int n)
{
	int* status;
	bool* matched;
	int* parent;

	status = (int*)malloc(n*sizeof(int));
	parent = (int*)malloc(n*sizeof(int));
	matched = (bool*)malloc(n*sizeof(bool));

	for(int i=0;i<n;i++)
	{
		status[i]=0;
		matched[i]=false;
	}
	
	stack<int> dstack;
	dstack.push(0);
	status[0]=1;
	while(!dstack.empty())
	{
		int curr = dstack.top();
		bool pushed = false;
		vector<int>::iterator it = arr[curr].begin();
		if(!arr[curr].empty())
		{
			if(status[*it]==0)
			{
				dstack.push(*it);
				status[*it] = 1;
				parent[*it] = curr;
	//			printf("Pushing %d \n",(*it)+1);
				pushed = true;
				arr[curr].erase(it);

			}
			else
			{
	//			printf("Erasing %d from %d's adjacency list\n",(*it)+1,curr+1);
				arr[curr].erase(it);
				continue;
			}
		}
		if(!pushed)
		{
			if(matched[parent[curr]]==0 && matched[curr]==0)
				{
					if(curr!=0)
					matched[parent[curr]]=1;
				}
			dstack.pop();
	//		printf("Popping %d\n",curr+1);
			status[curr] = 2;
		}
	}
	
	int res = 0;
	for(int i=0;i<n;i++)
	{
		res+= matched[i];
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr[n];
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		arr[x-1].push_back(y-1);
		arr[y-1].push_back(x-1);
	}	
	
	int ans = vertexCover(arr,n);
	printf("%d\n",ans);
	return 0;
}
