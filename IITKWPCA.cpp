#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t>0)
	{
		t--;
		string line;
		getline(cin,line);
		line = line + " ";
		int prev = 0;	
		set<string> myset;
		int i = 0;
		while(line[i]==' ')
				i++;	
		prev = i;
		for(;i<(int)line.length();)
		{
			while(line[i]!=' ')
				i++;
			myset.insert(line.substr(prev,i-prev));
			while(line[i]==' ')
				i++;	
			prev = i;
		}			
		printf("%d\n",(int)myset.size());
	}
}
