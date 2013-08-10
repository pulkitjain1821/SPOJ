#include <cstdio>
#include <cstdlib>
using namespace std;

void count(char arr[],int serial)
{
  int a[8] = {0,0,0,0,0,0,0,0};
	int x = 0;
	for(int i=0;i<3;i++)
	{
		x = x<<1;
		if(arr[i] == 'H')
			x = x + 1;			
	}
	//printf("index of case 1 is %d\n",x);
	a[x]++;
	for(int i=3;i<40;i++)
		{
			x = x&3;
			x = x<<1;
			if(arr[i]=='H')
				x = x+1;
			a[x]++;
			//printf("index of case %d is %d\n",i-1,x);
		}
	printf("%d ",serial);
	for(int i=0;i<8;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		int serial;
		scanf("%d",&serial);
		char arr[40];
		getchar();
		int i =0;
		while(i<40)
		{
			arr[i++] = getchar();
		}
		count(arr,serial);
	}
	return 0;
}
