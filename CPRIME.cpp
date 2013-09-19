#include<cstdlib>
#include<cstdio>
#include<cmath>
#define max  100000001
#define crude 6000000
using namespace std;

int LessThan(int num,int *count,int len)
{
	int lower = 0;
	int upper = len-1;
	int mid;
	while(upper>=lower)
	{
		mid = (upper + lower)/2;
		if(count[mid]==num)
			return mid+1;
		else if(count[mid] < num)
		{
			lower =  mid+1;
		}
		else
		{
			upper = mid - 1;
		}
	}	
	if(count[mid]<num)
		return mid+1;
	else
		return mid;
}

int main()
{
	bool *isPrime = (bool*)malloc((max/2 + 1)*sizeof(bool));
	int *cnt = (int*)malloc(crude*sizeof(int));
	int counter = 0;
	for(int i=0;i<(max/2 + 1);i++)
	{
		isPrime[i] = true;
	}
	//printf("Here!\n");
	isPrime[1] = 0;
	cnt[counter++]=2;
	for(long long int i=3;i<max;i+=2)
	{
		if(isPrime[i/2 + 1])
		{
			for(long long int j = i*i;j<max;j+= 2*i)
			{
				isPrime[j/2 + 1] = false;
			}
			cnt[counter++] = i;
		}
	}
	/*
	for(int k=0;k<101;k++)
	{
		printf("%d\n",cnt[k]);
	}*/
	
	//printf("%d\n",counter);
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
		{
			break;
		}
		int p_num = LessThan(num,cnt,counter);
		int mid  = p_num;
		double pi_num = num/log(num);
		double final = round(1000*(abs(p_num - pi_num))/(double)p_num)/10;
		printf("%.1f\n",final);
		//printf("%dth prime is %d, %dth prime is %d, %dth prime is %d, %dth prime is %d\n",mid-2,cnt[mid-2],mid-1,cnt[mid-1],mid,cnt[mid],mid+1,cnt[mid+1]);
	}
}
