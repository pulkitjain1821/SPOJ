#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<map>
#include<algorithm>
#include<cctype>
using namespace std;
int main()
{
	int sum =0;
	int t,num;
	char op[7];
	scanf("%d",&t);
	map<int,int> mymap;
	for(int i=0;i<t;i++)
	{
		scanf("%s",op);
		//printf("%s is the operation\n",op);
		scanf("%d",&num);
		
		//printf("%s is the operation and %d is the operand\n",op,num);
		
		if(strcmp(op,"insert")==0)
		{
			if(mymap.count(num)<=0)
			{
				mymap[num] = 1;
			}
			else
			{
				mymap[num]++;
			}
			sum++;
		}
		else
		{
			if(mymap.count(num)>0)
			{
				mymap[num]--;
				if(mymap[num]==0)
				{
					mymap.erase(num);
				}
				sum--;
			}
		}

		//printf("%d is mymap.size() and %d is sum\n",mymap.size(),sum);
		if(mymap.size()>=2 && sum>mymap.size())
		{
			printf("both\n");
		}
		else if(mymap.size()<2 && sum>mymap.size())
		{
			printf("homo\n");
		}
		else if(mymap.size()>=2 && sum<=mymap.size())
		{
			printf("hetero\n");
		}
		else
		{
			printf("neither\n");
		}
	}
	return 0;
}
