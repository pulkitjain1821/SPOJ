#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef struct cell
{
	int p;
	int c;
}
cell;

cell* factorise(int a)
{
	int num = a;
	cell* fact = (cell*)malloc(10*sizeof(cell));
	int iter = 0;
	int count = 0;
	while(num%2==0)
	{
		num /= 2;
		count++;
	}
	if(count!=0)
	{
		fact[iter].c = count;
		fact[iter].p = 2;
		iter++;
	}
	for(int i=3;i<=sqrt(a);i+=2)
	{
		count = 0;
		while(num%i==0)
		{
			num/= i;
			count++;
		}	
		if(count!=0)
		{
			fact[iter].p = i;
			fact[iter].c = count;
			iter++;
		}
	}
	if(num>1)
		{
			fact[iter].p = num;
			fact[iter].c = 1;
			iter++;
		}
	fact[iter].c = fact[iter].p = -1;
	return fact;
}
int main()
{
	int n,m;
	int t = 1;
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		cell* facta = factorise(n);
		cell* factb = factorise(m);
		int ptra = 0, ptrb = 0;
		int dist = 0;
		int count = 0;
		while(facta[ptra].p != -1 && factb[ptrb].p != -1)
		{
			if(facta[ptra].p == factb[ptrb].p)
			{
				dist += abs(facta[ptra].c - factb[ptrb].c);
				count++;
				ptra++;
				ptrb++;
			}
			else if(facta[ptra].p < factb[ptrb].p)
			{
				dist += facta[ptra].c;
				count++;
				ptra++;
			}
			else
			{
				dist += factb[ptrb].c;
				count++;
				ptrb++;				
			}		
		}
		
		while(facta[ptra].p != -1)
		{
			dist +=  facta[ptra].c;
			count++;
			ptra++;
		}
		while(factb[ptrb].p != -1)
		{
			dist +=  factb[ptrb].c;
			count++;
			ptrb++;
		}
		free(facta);
		free(factb);
		printf("%d. %d:%d\n",t++,count,dist);
	}
	return 0;
}
