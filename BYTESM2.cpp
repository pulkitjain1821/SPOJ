#include <stdio.h>
#include <stdlib.h>

int main()
{
  int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		int m,n;
		scanf("%d%d",&m,&n);
		int arr[m][n];
		int ans[m][n];
		int i,j;
		for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
					{
						int x;
						scanf("%d",&x);
						arr[i][j]=x;
					
						if(i==0)
							ans[i][j] = arr[i][j];
						else
						{
							int left = 0;
							int mid = 0;
							int right = 0;
							
							mid = ans[i-1][j];
							if(j>0)
								left = ans[i-1][j-1];
							if(j<n-1)
								right = ans[i-1][j+1];
						
							int max =0;
							if(mid > left)
								{
									if(mid > right)
										max = mid;
									else
										max = right;
								}
							else
								{
									if(left > right)
										max = left;
									else
										max = right;
								}
							ans[i][j] =  max + arr[i][j];
						}
					
					}
			}
	
			int answer = 0;
			for(i=0;i<n;i++)
				{
					if(ans[m-1][i]>answer)
						answer = ans[m-1][i];
				}
			/*printf("----------");
			for(int k=0;k<m;k++)
				{
					for(int l=0;l<n;l++)
						{
							printf("%d ",ans[k][l]);
						}
					printf("\n");
				}*/
			printf("%d\n",answer);
	}
	return 0;
}
