#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

int decode(char * a, long long int* d,int n)
{
  d[0] = 1;
	
	if(n>1)
	d[1] = 1;
	
	if(n>1)
	if((a[1]-'0')+(a[0]-'0')*10  <= 26 && a[1]!='0')
	{
		d[1] = 2;
	}
	for(int i=2;i<n;i++)
	{
		if(a[i]=='0')
		{
			d[i]=d[i-2];
		
			if(i+1<n)
			{
				d[i+1]=d[i-2];
				i++;
			}
		}
		else
		{
			if(i==2)
			{
				if(a[1]=='0')
					d[i]=d[i-2];
				else
				{
					if((a[i]-'0')+(a[i-1]-'0')*10  <= 26)
					{
							d[i] = d[i-1] + d[i-2];
					}
				else
					d[i] = d[i-1];	

				}
			}
			else
			{
				if((a[i]-'0')+(a[i-1]-'0')*10  <= 26)
					{
							d[i] = d[i-1] + d[i-2];
					}
				else
					d[i] = d[i-1];	
			}
		}
	}
	return d[n-1];
}
int main()
{
	long long int* d = (long long int*)malloc(5000*(sizeof(long long int)));			//n-2th iteration
	char * a = (char*)malloc(5000*sizeof(char));
	int p=0;
	while(1)
	{
		char c = getchar();
		if(c=='0' && p==0)
		{
			break;
		}
		if(c=='\n')
		{
			printf("%d\n",decode(a,d,p));
			p=0;
		}
		else
		{
			a[p++]=c;
		}
	}	
	return 0;
}
