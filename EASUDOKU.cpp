#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

void display(int arr[][9])
{
  for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			{
				printf("%d ",arr[i][j]);
			}
		printf("\n");
	}
}

list<int> find_possible(int arr[][9],int row,int col)
{
	list<int> poss;
	int possible[9] = {1,1,1,1,1,1,1,1,1};
	for(int i=0;i<9;i++)
	{
		if(arr[row][i]!=0)
			possible[arr[row][i]-1]=0;
	}
	for(int i=0;i<9;i++)
	{
		if(arr[i][col]!=0)
			possible[arr[i][col]-1]=0;
	}
	
	int sqrow = (row/3)*3;
	int sqcol = (col/3)*3;
	
	for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
			{
				if(arr[sqrow+x][sqcol+y]!=0)
					possible[arr[sqrow+x][sqcol+y]-1]=0;
			}
	for(int b =0;b<9;b++)
	{
		if(possible[b]!=0)
			poss.push_back(b+1);
	}
	
	return poss;
}

int solve(int arr[][9], int i, int j)
{
	if(i>=9 || j>=9 )
		return 1;
	if(arr[i][j]==0)
		{
			list<int> possible = find_possible(arr,i,j);			
			if(possible.empty())
				return 0;
			while(!possible.empty())
			{
				int front = possible.front();
				possible.pop_front();
				arr[i][j] = front;
				int trial = solve(arr,(i*9+j+1)/9,(i*9+j+1)%9);				
				if(trial==1)
					return 1;
			}
			arr[i][j] = 0;
			return 0;
		}
	else
		return solve(arr,(i*9+j+1)/9,(i*9+j+1)%9);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		int arr[9][9];
		for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					{
						int x;
						scanf("%d",&x);
						arr[i][j] = x;
					}
			}
		if(solve(arr,0,0))
			display(arr);
		else
			printf("No solution\n");
	
	}
	return 0;
}
