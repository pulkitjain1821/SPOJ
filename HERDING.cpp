#include<cstdio>
#include<cstdlib>
#include<list>
#include<queue>
using namespace std;

int get(char c, int width, int base)
{
	switch(c)
	{
		case 'S': return base+width;
		case 'N': return base-width;
		case 'E': return base+1;
		case 'W': return base-1;
	}
}

int connected(list<int> arr[], int len)
{
	int* status = (int*)malloc(len*sizeof(int));
	for(int i=0;i<len;i++)
	{
		status[i] = -1;
	}
	int count = 0;
	for(int i=0;i<len;i++)
	{
		
		if(status[i]!=-1)
			continue;
		count++;
		int source = i ;
		queue<int> mine;
		mine.push(source);
		status[source] = 0;
		while(!mine.empty())
		{
			int x = mine.front();
			mine.pop();
			status[x] = count;
			for(list<int>::iterator it = arr[x].begin();it!=arr[x].end();++it)
			{
				if(status[*it]==-1)
				{
					mine.push(*it);
					status[*it] = 0;
				}
			}
		
		}
	}
	return count;
}

int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	list<int>* arr = new list<int> [n*m];// = (list<int>*)malloc(n*m*sizeof(list<int>));
	//printf("Here!!! n=%d, m=%d\n",n,m);
	char* str = (char*)malloc((m+1)*sizeof(char));
	for(int i=0;i<n;i++)
	{
		scanf("%s",str); 
	//	printf("\"%s\" recieved\n",str);
		for(int j=0;j<m;j++)
		{
			x = get(str[j],m,i*m + j);
	//		printf("X is %d\n",x);
			arr[x].push_back(i*m + j);
			arr[i*m + j].push_back(x);
		}
	}
	//printf("Now starting\n");
	printf("%d\n",connected(arr,n*m));
	return 0;
}
