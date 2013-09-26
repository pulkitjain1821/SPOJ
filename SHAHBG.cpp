#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	bool arr[20001];
	for(int i=0;i<=20000;i++)
	{
		arr[i] = false;
	}
	int count =0;
	int num;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&num);
		arr[num] = true;
		int set = 0;
		if(num-1>=0 && arr[num-1]==true)
			set++;
		if(num+1<=20000 && arr[num+1]==true)
			set++;
		if(set == 0)
			count++;
		if(set==2)
			count--;
		printf("%d\n",count);
	}
	printf("Justice\n");
	return 0;
}
