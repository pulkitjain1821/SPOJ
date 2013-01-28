#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
		{
			t--;
			int a,b;
			scanf("%d%d",&a,&b);
			int wts[a];
			for(int i=0;i<a;i++)
				scanf("%d",&wts[i]);
				
			int count=0;
			int start=0;
			int ans=0;int tstart=0;
			unsigned int sum=0;
			for(int i=0;i<a;i++)
				{
					sum+=wts[i];
					if(sum<=b)
						{
							
							ans=sum;
							count++;
							start=tstart;
						}
					else
						{
							tstart++;
							sum = sum-wts[tstart-1];
						}
				}
			
			ans=0;	
			for(int i=0;i<count;i++)
				ans+=wts[i];
			sum = ans;	
			for(int i=0;i< a-count;i++)
				{
					sum = sum - wts[i] + wts[i+count];
					if(ans > sum)
						ans = sum;
				}		
			printf("%d %d\n",ans,count);
		}
	return 0;	
}
