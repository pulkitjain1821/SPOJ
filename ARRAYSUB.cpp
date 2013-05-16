#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

void display(int *p,int n)
{
  for(int i=0;i<n;i++)
		printf("%d ",p[i]);
}

int max(int x, int y)
{
	if(x>y)
		return x;
	return y;
}

int find_max(int*a, int root, int l, int r , int u , int v)
{
	int t0 = 0;
	if(u <=l && r<=v)
		{
			//printf("returning root %d\n",a[root]);
			return a[root];
		}
	int mid = (l+r)/2;
	int l_child = 2*root;
	int r_child = l_child+1;
	int t1,t2;
	t1 = t2 = 0;
	if(u<=mid) 
		t1 = find_max(a,l_child,l,mid,u,v);
	if(v>mid)
		t2 = find_max(a,r_child,mid+1,r,u,v);
	//printf("returning max %d",max(t1,t2));	
	return(max(t1,t2));	 	
}

int main()
{
	int n;
	scanf("%d",&n);	
	int log_n = ceil(log(n)/log(2));
	//printf("%d\n",log_n);
	
	int new_n = 1<<log_n;
	int *a = (int *)malloc(2*new_n*sizeof(int));
	int i;
	a[0]=-1;
	for(i =new_n;i< new_n + n; i++ )
		{
			int s;
			scanf("%d",&s);
			a[i]=s;
		}
	for(;i<2*new_n;i++)
		a[i]=0;	
	
	for(int l =log_n-1;l>=0;l--)
		{
			int tmp = 1<<l;
			for(int j =	tmp;j<2*tmp;j++)
				a[j]=max(a[2*j],a[2*j+1]);
		}
	int k;
	scanf("%d",&k);	
	for(int i =0;i+k<=n;i++)
		{
			printf("%d ",find_max(a,1,new_n,2*new_n-1,new_n+i,new_n+i+k-1));
		}
	
			
		
	//display(a,2*new_n);	
	return 0;
}
