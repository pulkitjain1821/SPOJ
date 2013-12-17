#include<cstdio>
#include<cstdlib>
using namespace std;
 
unsigned short count[301][301][10];
int arr[300][300];
 
int readInt () 
{
        bool minus = false;
        int result = 0;
        char ch;
        ch = getchar_unlocked();
        //ch = getchar();
        while (true) {
                if (ch == '-') break;
                if (ch >= '0' && ch <= '9') break;
                //ch = getchar();
                ch = getchar_unlocked();
        }
        if (ch == '-') minus = true; else result = ch-'0';
        while (true) {
                ch = getchar_unlocked();
                //ch = getchar();
                if (ch < '0' || ch > '9') break;
                result = result*10 + (ch - '0');
        }
        if (minus)
                return -result;
        else
                return result;
}
 
int main()
{
	int n;
	n = readInt();
	//scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//scanf("%d",*(arr+i)+j);
			//arr[i][j]--;
			arr[i][j] = readInt() -1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		count[i+1][1][arr[i][0]]++;
	}
 
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int k=0;k<10;k++)
			{
				count[i+1][j+1][k] = count[i+1][j][k];
			}
			count[i+1][j+1][arr[i][j]]++;
		}
	}
 
	for(int j=0;j<n;j++)
	{
		for(int i=1;i<n;i++)
		{
			for(int k=0;k<10;k++)
			{
				count[i+1][j+1][k] += count[i][j+1][k];
			}
		}
	}
 
	/*for(int k=0;k<10;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",count[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}*/
	int q;
	scanf("%d",&q);
	int x1,x2,y1,y2;
	
	for(int i=0;i<q;i++)
	{
		//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		//x1--;x2--;y1--;y2--;
		
		x1 = readInt();
		y1 = readInt();
		x2 = readInt();
		y2 = readInt();
		x1--;y1--;
		int ans =0;
		for(int k=0;k<10;k++)
		{
			int temp = count[x2][y2][k] - count[x2][y1][k] - count[x1][y2][k] + count[x1][y1][k];
			if(temp > 0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
