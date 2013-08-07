#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		int n;
		int m;
		scanf("%d%d",&n,&m);
		int arr[n][m];
		int i=0;
		int j=0;
		getchar_unlocked();							// new line
		while(i<n)
		{
			j=0;
			while(j<m)
			{
				
				arr[i][j++] = getchar_unlocked() - '0';
			}
			getchar_unlocked();						// new line
			i++;
		}
	
		int answer[n][m];
		queue<int> mine;
		
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					answer[i][j] = n+m+1;
				}
			}

	
		int status[m*n];
		for(int k=0;k<m*n;k++)
		{
			status[k]=0;
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]==1)
					{
						answer[i][j] = 0;
						mine.push(i*m+j);
						status[i*m+j] = 1;
					}
			}
		}	
			
		
		while(!mine.empty())
		{
			int curr = mine.front();
			int row = curr/m;
			int col = curr%m;  
			mine.pop();

			if(row+1 <n)
			{
				if(status[(row+1)*m + col]==0)
					{
						mine.push((row+1)*m + col);
						status[(row+1)*m + col] = 1;
						answer[row+1][col] = answer[row][col]+1;
					}
			}
			if(row-1>=0)
			{
				if(status[(row-1)*m + col]==0)
					{
						mine.push((row-1)*m + col);
						status[(row-1)*m + col] = 1;
						answer[row-1][col] = answer[row][col]+1;
					}
			}
			if(col+1<m)
			{
				if(status[row*m + col + 1]==0)
					{
						mine.push(row*m + col+1);
						status[row*m + col+1] = 1;
						answer[row][col+1] = answer[row][col]+1;
					}
			}
			if(col-1>=0)
			{
				if(status[row*m + col - 1]==0)
					{
						mine.push(row*m + col-1);
						status[row*m + col-1] = 1;
						answer[row][col-1] = answer[row][col]+1;
					}
			}
			status[row*m+col]=2;
		}

		for(int z=0;z<n;z++)
			{
				for(int x=0;x<m;x++)
					{
						printf("%d ",answer[z][x]);
					}
				printf("\n");
			}
		//printf("bfs done = %d\n",bfscount);
	}
	
	return 0;
}
