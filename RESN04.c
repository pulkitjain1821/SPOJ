#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
		{
		 int n;
		 scanf("%d",&n);
		 int k;
		 int ans =0;
		 for(k=0;k<n;k++)
		 	{
		 		int s ;
		 		scanf("%d",&s);	
		 		ans+= s/(k+1);
		 	}
		 if(ans%2 == 0)
		 	printf("BOB\n");
		 else
		 	printf("ALICE\n");	
		}
	return 0;
} 

