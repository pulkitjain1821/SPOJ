#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
 
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
 
 
void update(long long int* arr, int ind, int val)
{
	while(ind>=1)
	{
		arr[ind]+= val;
		ind /=2;
	}
}
 
long long int sum(long long int* arr,int root,int left, int right, int start, int end)
{
	if(start <= left && end >= right)
		return arr[root];
	int leftchild = root*2;
	int rightchild = leftchild + 1;
	int mid = (left + right)/2;
	long long int temp1 = 0 , temp2 = 0;
	if( start <= mid)
		temp1 = sum(arr,leftchild,left,mid,start,end);
	if(end > mid)
		temp2 = sum(arr,rightchild,mid+1,right,start,end);
	return temp1+temp2;
}
 
int main()
{
	int n,q,temp,i;
	scanf("%d%d",&n,&q);
	int log_n = ceil(log(n)/log(2));
	int num = 1<<log_n;
	long long int *arr = (long long int*)malloc(2*num*sizeof(long long int));
	arr[0] = -1;
	for(i=0;i<n;i++)
	{
		//scanf("%d",&temp);
		
		arr[num+i] = readInt();
	}
	for(;i+num<2*num;i++)
	{
		arr[i+num] = 0;
	}
	
	for(int l=log_n-1;l>=0;l--)
	{
		for(int start = 1<<l;start< 1<<(l+1);start++)
		{
			arr[start] = arr[2*start] + arr[2*start+1];
		}
	}
	
	
	/*for(i=0;i<2*num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	*/
	int start,end;
	char c[2];
	for(i=0;i<q;i++)
	{
		//printf("Handling query number %d\n",i);
		scanf("%s",&c);
		//scanf("%d%d",&start,&end);
		start = readInt();
		end = readInt();
		start += num;
		if(c[0]=='S')
		{
			//printf("Asking for sum\n");
			end += num;
			//printf("start = %d, end = %d\n",start,end);
			printf("%lld\n",sum(arr,1,num,2*num-1,start,end));
		}
		if(c[0]=='G')
		{
			//printf("Asking for give\n");
			update(arr,start,end);
		}
		if(c[0]=='T')
		{
			//printf("Asking for take\n");
			update(arr,start,-end);
		}
	}
	free(arr);
	return 0;
}  
