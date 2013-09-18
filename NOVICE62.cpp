/* 
found a new way for calculating dearrangements

D(n) =  sum(i=1 to n-2) {choose(n,i)*D(n-i)}
D(n) = (n-1){D(n-1) + D(n-2)}

*/


#include<cstdio>
#include<cstdlib>
#define p 1000000007
using namespace std;

void fill(int * dearr, int max)
{
	dearr[0] = dearr[1] = 0;
	dearr[2] = 1;
	for(int i = 3;i<=max;i++)
	{
		long long temp = (dearr[i-1] + dearr[i-2])%p;
		temp = ((i-1)*temp)%p;
		dearr[i] = temp;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int arr[t];
	int max = 0;
	for(int i=0;i<t;i++)
	{
		scanf("%d",arr+i);	
		if(max < arr[i])
			max = arr[i];
	}
	int* dearr = (int*)malloc((max+1)*sizeof(int));
	fill(dearr,max);
	for(int i=0;i<t;i++)
	{
		printf("%d\n",dearr[arr[i]]);
	}
	return 0;
}
