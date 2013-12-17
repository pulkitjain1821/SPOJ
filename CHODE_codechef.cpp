#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
char freq1 [26];
char str [150001];
using namespace std;
 
typedef struct
{
	char c;
	int  f;
} data;
 
void reset(data* arr)
{
	for(int i=0;i<26;i++)
	{
		arr[i].c = i + 'a';
		arr[i].f = 0;
	}
}
 
bool comp(const data& a, const data &b)
{
	return a.f == b.f ? a.c < b.c : a.f < b.f ;
}
 
int main()
{
	int t;
	scanf("%d",&t);
	data freq2[26];
	for(int l=0;l<t;l++)
	{
		scanf("%s",freq1);
		getchar();
		char c;
		int len  = 0;
		while((c=getchar())!='\n')
		{
			str[len++] = c;
		}
		str[len] = '\0';
		//printf("The initial frequency sequence is: %s\n",freq1);
		//printf("The text is: %s\n",str);
		reset(freq2);
		//printf("Length of text was %d\n",len);
		for(int i=0;i<len;i++)
		{
			if(str[i] >= 'a' && str[i] <='z')
			{
				freq2[str[i]-'a'].f++;
			}
			else if(str[i] >= 'A' && str[i] <='Z')
			{
				freq2[str[i]-'A'].f++;
			}
		}
		sort(freq2,freq2+26,comp);
		/*for(int i=0;i<26;i++)
		{
			printf("%c",freq2[i].c );
		}
		printf("\n--\n");*/
		map<char,int> one;
		map<char,int> two;
		for(int i=0;i<26;i++)
		{
			one[freq1[i]] =  two[freq2[i].c] = i;
		}
		
		for(int i=0;i<len;i++)
		{
			if(str[i] >= 'a' && str[i] <='z')
			{
				str[i] = freq1[two[str[i]]];
			}
			else if(str[i] >= 'A' && str[i] <='Z')
			{
				str[i] = freq1[two[str[i]-'A' + 'a'] ] + 'A' - 'a';
			}
		}
		printf("%s\n",str);
	}
	return 0;
} 
