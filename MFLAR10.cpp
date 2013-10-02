#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{

	string line,word;
	while(true)
	{
		getline(cin,line);
		if(line[0]=='*')
			break;
		
		stringstream str(line);
		str >> word;
		char c = word[0];
		if(c>='a')
			c = c-'a' + 'A';
		bool done = false;
		while(str >> word)
		{
			if(word[0]==c || word[0] == c-'A'+'a')
				continue;
			else
				{
					printf("N\n");
					done = true;
					break;
				}
		}
		if(!done)
			printf("Y\n");
	}
	return 0;
}
