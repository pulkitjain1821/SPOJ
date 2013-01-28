#include <cstdio>
#include <string.h>
#include <cstdlib>
using namespace std;
int main()
{
 int n;
 while(1)
 {
	 scanf("%d",&n);
	 if(n==0)
		break;
	 char* s = (char*)malloc(200*sizeof(int));
	 scanf("%s",s);
	 int l = strlen(s);
	 char arr[l/n][n];
	 
	 for(int i=0;i<l;i++)
		arr[i/n][i%n] = s[i];
	/*
	 for(int i =0;i<l/n;i++)
		{
			for(int k =0;k<n;k++)
				printf("%c ",arr[i][k]);
			printf("\n");
		}
	*/ 
	//printf("---\n");	
	 for(int i=1;i<l/n;i=i+2)
		for(int k=0;k<n/2;k++)
			{
				char c = arr[i][k];
				arr[i][k] = arr[i][n-k-1];
				arr[i][n-k-1] = c;
			}
	/*	 
	 for(int i =0;i<l/n;i++)
		{
			for(int k =0;k<n;k++)
				printf("%c ",arr[i][k]);
			printf("\n");
		}
	 */
	 for(int z=0;z<n;z++)
			for(int f =0;f<l/n;f++)
					printf("%c",arr[f][z]);
	 printf("\n");	
 }	
 return 0;
}
