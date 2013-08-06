#include <cstdio>
#include <string.h>
#include <cstdlib>

using namespace std;

int isCapital(char a)
{
  return a>=65 && a<=90;
}

int isLower(char a)
{
	return a>=97 && a<=122;	
}

int is_cpp(char* a , int len)
{
	for(int i=0;i<len;i++)
		{
			if(isCapital(a[i]))
				return 0;
			if(a[i]=='_' && (i==0 || i==len-1))
				return 0;
			if(a[i]=='_' && a[i+1]=='_')
				return 0;
		}
	return 1;
}

int isJava(char* a, int len)
{
	for(int i=0;i<len;i++)
	{
		if(isCapital(a[i])&&i==0)
			return 0;
		if(a[i]=='_')
			return 0;
	}
	return 1;
}

void convertToJava(char* a, int len)
{
	for(int i=0;i<len;i++)
		{
			if(a[i]=='_')
				{
					i++;
					putchar(a[i]-'a'+'A');
				}
			else
			{
				putchar(a[i]);
			}
		}	
	putchar('\n');
}

void convert_to_cpp(char* a, int len)
{
	for(int i=0;i<len;i++)
	{
		if(isCapital(a[i]))
			{
				putchar('_');
				putchar(a[i]-'A'+'a');
			}
		else
			{
				putchar(a[i]);
			}
	}
	putchar('\n');
}

void convert(char* a, int len)
{
	if(is_cpp(a,len))
		convertToJava(a,len);
	else if (isJava(a,len))
		convert_to_cpp(a,len);
	else
		printf("Error!\n");
}

int main()
{
	char arr[100];
	int p=0;
	char prev;
	while(1)
	{
		char c = getchar();
		if(c==EOF && prev!='\n') 
			{
				convert(arr,p);
				break;
			}
		else if (c==EOF)
			{
				break;
			}
		else if(c=='\n')
			{
				convert(arr,p);
				p=0;
			}
		else
		{
			arr[p++]=c;
		}
		prev = c;
	}	
	return 0;
}
