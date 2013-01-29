#include <cstdio>
using namespace std;

void display(int a[],int s, int e)
{
	printf("The array is --\n");
	for(int i=s;i<=e;i++)
		printf("%d ",a[i]);
	printf("\n");
}

long long int inversions(int a[],int s,int e)
{
//	printf("received value of s=%d,e=%d\n",s,e);
//	display(a,s,e);	
	if(s==e)
		{
	//		printf("0 is the answer of inversion(%d,%d) is\n",s,e);
			return 0;
		}
	else
		{
			long long int t1;
			t1 = inversions(a,s,(s+e)/2);
			t1+=inversions(a,((s+e)/2)+1,e);
			int ptr1 = s;
			int ptr2 = ((s+e)/2) +1;
			int tmp[e-s+1];
		//	printf("%d-----building tmp\n",a[s]);
		//	printf("%d=====building tmp\n",a[((s+e)/2) +1]);
			
		//	printf("building tmp\n");
			for(int i=0;i<e-s+1;i++)
				{
					if(ptr2>e)
						{
							tmp[i]=a[ptr1++];
						t1+=(ptr2 - ((s+e)/2) -1);
						}
					else if(ptr1>(s+e)/2)
							tmp[i]=a[ptr2++];
						 	
					else if(a[ptr1]<=a[ptr2])
						{
							tmp[i]=a[ptr1];
							ptr1++;
							t1+=(ptr2 - ((s+e)/2) -1);
						}
					else
						{
							tmp[i]=a[ptr2];
							ptr2++;
							
						}	
				}
		//	printf("displaying tmp\n");
		//	display(tmp,0,e-s);	
			for(int i=s;i<=e;i++)
				a[i]=tmp[i-s];
		//	printf("Array after inversion(%d,%d) is\n",s,e);
		//	display(a,s,e);	
		//	printf("%lld\n",t1);
			return t1;
		}
	
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
		{
			t--;
			int n;
			scanf("%d",&n);
			int a[n];
			for(int i=0;i<n;i++)
				scanf("%d",&a[i]);
			printf("%lld\n",inversions(a,0,n-1));
		//	printf("The Array now is as follows--\n");
		//	for(int i=0;i<n;i++)
		//		printf("%d ",a[i]);
		//	printf("\n");	
		
		}
	return 0;
}
