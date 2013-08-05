#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>

int main()
{
  while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int arr[n];
		int i=0;
		while(i<n)
		{
			scanf("%d",arr+i);
			i++;
		}
		
		int auxArr[n] ;
		int search =1;
		i=0;
		int top = 0;
		
		while(i<n)
		{
			if(auxArr[top-1]==search)
			{
				search++;
				top--;
				i--;
			}
			
			else if(arr[i]==search)
			{
				search++;
			}
			else
			{
				auxArr[top++]=arr[i];
			}
			i++;
		}
	
		int sorted = 1;
		int j;
		for(j=0;j<top-1;j++)
		{
			if(auxArr[j+1]>auxArr[j])
			{
				sorted = 0;
				break;
			}
		}
		
		if(sorted==1)
			printf("yes\n");
		else
			printf("no\n");	
	
	}
	return 0;
}
