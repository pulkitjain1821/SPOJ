#include <cstdio>
using namespace std;

int binsearch(int * x,int num)
{
	int l = 0;
	int h = 18259;
	while(h>=l)
		{
			if(x[(h+l)/2]==num)
				return 1;
			else if (x[(h+l)/2]<num)
				l = (h+l)/2 +1;
			else
				h = (h+l)/2 -1;
		}
	return 0;
}

int main()
{
	int arr[18260];
	for(int i=0;i<=18260;i++)
		{
			arr[i] = i*(6+(i-1)*3) + 1;
			if(arr[i]>1000000000)
				break;
		}
	
	while(1)
		{
			int n;
			scanf("%d",&n);
			if(n==-1)
				break;
			if(binsearch(arr,n))
				printf("Y\n");
			else
				printf("N\n");
		}
	return 0;
}
