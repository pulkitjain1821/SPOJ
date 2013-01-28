#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <cstdio>
using namespace std;
int main()
{
 int t;
 cin>>t;
 getchar();
 while(t)
 {
	t--;
	string str;
	getline(cin,str);
	int l = str.length();
	int i=0;
	while(str[i]!='.' && i<l)
		i++;
	
	char flt [4];
	//flt[5]='\0';
	int j=0;
	i++;
	while(i<l)
			flt[j++]=str[i++];
	while(j<4)
			flt[j++]='0';	
	//cout<<flt<<endl;
	int val = atoi(flt);
	//cout<<"--"<<val<<endl;
	int tmp = val;
	int ans =1;
	while(val%10000!=0)
		val = tmp*(++ans);
	printf("%d\n",ans);	
 }
 
  return 0;       
}
