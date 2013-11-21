#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#define inf 100000000
using namespace std;

char arr[500][500];
int dist[500][500];
bool expand[500][500];
queue<int> mine;
char status[500][500];

void getAdj(int top,int c,int r,char arr[][500], int *adj)
{
	int i = top/c;
	int j = top%c;
	adj[4] = 0;
	if(i-1>=0 && arr[i-1][j]!='#')
	{
		adj[adj[4]++] = (i-1)*c + j;
		//adj->push_back((i-1)*c + j);
	}
	if(i+1<r && arr[i+1][j]!='#')
	{
		adj[adj[4]++] = (i+1)*c + j;
		//adj->push_back((i+1)*c + j);
	}
	if(j+1<c && arr[i][j+1]!='#')
	{
		adj[adj[4]++] = i*c + j + 1;
		//adj->push_back(i*c + j+1);
	}
	if(j-1>=0 && arr[i][j-1]!='#')
	{
		adj[adj[4]++] = i*c + j-1;
		//adj->push_back(i*c + j-1);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int r,c;
	for(int l=0;l<t;l++)
	{
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
		{
			getchar();
			for(int j=0;j<c;j++)
			{
				arr[i][j] = getchar();
				dist[i][j] = inf;
				status[i][j] = arr[i][j];
				if(arr[i][j]!='#')
				{
					expand[i][j] = true;
				}
				if(arr[i][j]>='a'&&arr[i][j]<='z')
				{
					mine.push(i*c + j);
					dist[i][j] = 0;
				}
			}
		}
		
	
		int top,row,col;
		while(!mine.empty())
		{
			top = mine.front();
			mine.pop();
			if(expand[top/c][top%c])
			{
				int adj[5];
				getAdj(top,c,r,arr,adj);
				for(int k=0;k<adj[4];k++)
				{
					row = adj[k]/c;
					col = adj[k]%c;
					if(status[row][col]=='.')
					{
						dist[row][col] = dist[top/c][top%c] + 1;
						status[row][col] = status[top/c][top%c];
						mine.push(adj[k]);
						expand[row][col] &= true; 
					}
					else if(expand[row][col] && status[row][col] >= 'a' && status[row][col] <= 'z')
					{
						if(status[top/c][top%c]!=status[row][col] && dist[top/c][top%c]+1==dist[row][col])
						{
							status[row][col] = '*';
							expand[row][col] &= false;
						}
					}
				}
				expand[top/c][top%c] = false;
			}
		}
		for(int s=0;s<r;s++)
		{
			for(int z=0;z<c;z++)
			{
				printf("%c",status[s][z]);
			}
			printf("\n");
		}
		printf("\n");
	}	
	return 0;
}
