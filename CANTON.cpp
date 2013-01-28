#include <cstdio>
using namespace std;
int main()
{	
	int t;
	scanf("%d",&t);
	while(t)
		{
			t--;
			int n;
			scanf("%d",&n);
			int k=1;int tmp =n;
			while(k*(k+1)/2 < n)
				k++;
			int off = n- k*(k-1)/2;
			printf("TERM %d is %d/%d\n",tmp,off,k+1-off);
		}
	return 0;
}
