/* Question asked in DirectI intern hiring test 2013 */

#include<cstdlib>
#include<cstdio>
#include<stack>
using namespace std;
typedef struct data
{
	int rem;
	int quo;
};
int main()
{
	char arr[500];
	char c;
	int len=0;
	while((c=getchar())!='\n' && c!=EOF)
	{
		arr[len++]=c;
	}

    stack<data> myStack;
    int x = 0;
	for(int i=0;i<len;i++)
    {
    	x++;
    	if(arr[i]=='(')
    	{
    		data point;
    		point.rem = x-2;
    		point.quo = arr[i-1] - '0';
    		x = 0;
    		myStack.push(point);
		}
    	else if (arr[i]==')')
    	{
    		data temp = myStack.top();
    		myStack.pop();
			x--;    		
    		x = (temp.quo * x )+ temp.rem;
    	}
    }
	printf("%d\n",x);
	return 0;
}
