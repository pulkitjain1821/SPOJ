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
    	if(arr[i+1]=='(' && i+1 <len)
    	{
    		data point;
    		point.rem = x-1;
    		point.quo = arr[i] - '0';
    		x = 0;
    		i++;
    		myStack.push(point);
		}
    	else if (arr[i+1]==')'&& i+1 <len)
    	{
    		data temp = myStack.top();
    		myStack.pop();
    		x = temp.quo * x + temp.rem;
    		
    		i++;
    	}
    }
	printf("%d\n",x);
	return 0;
}
