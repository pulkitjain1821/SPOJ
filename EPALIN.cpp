#include <cstdio>
#include <string.h>
#include <cstdlib>
using namespace std;

int border(char* str,int len)
{
	int bor[len];
	bor[0]=0;
	int i=1;
	int j=0;
	while(i<len)
		{
			if(str[j]==str[i])
				{
					bor[i++]=j+1;
					j++;
				}
			else
				{
					if(j>0)
						j=bor[j-1];
					else
						{
							bor[i++]=0;
							j=0;
						}
					
				}
		}
		
	return bor[len-1];
}

int main()
{
			char* a =(char*)malloc(100000*sizeof(char));
			int p=0;
			char c;
			while(1)
				{
					c=getchar_unlocked();
					
					if(c==EOF)
						break;
					
					if(c!='\n')
						a[p++]=c;
						
					else
						{
							/*putchar('$');
							for(int z=0;z<p;z++)
							putchar_unlocked(a[z]);
							putchar('\n');
							*/
							
							char* s = (char*)malloc((2*p + 1)*sizeof(char));

							for(int i=p-1;i>=0;i--)
								s[i]=a[p-1-i];
							s[p]='#';
							
							for(int i=0;i<p;i++)
								s[p+1+i]=a[i];
			
							for(int z=0;z<p;z++)
							putchar_unlocked(a[z]);
							for(int i= p-border(s,strlen(s))-1;i>=0;i--)
								putchar_unlocked(a[i]);
							printf("\n");
						
							p=0;
						}
				}
	return 0;
}
