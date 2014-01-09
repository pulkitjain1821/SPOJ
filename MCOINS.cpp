#include<cstdio>
#include<cstdlib>
using namespace std;
bool arr[1000001];
int readInt () 
{
        bool minus = false;
        int result = 0;
        char ch;
        ch = getchar_unlocked();
        while (true) {
                if (ch == '-') break;
                if (ch >= '0' && ch <= '9') break;
                ch = getchar_unlocked();
        }
        if (ch == '-') minus = true; else result = ch-'0';
        while (true) {
                ch = getchar_unlocked();
                if (ch < '0' || ch > '9') break;
                result = result*10 + (ch - '0');
        }
        if (minus)
                return -result;
        else
                return result;
}
int main()
{
	int k,l,m,n;
	//scanf("%d%d%d",&k,&l,&m);
	k = readInt();
	l = readInt();
	m = readInt();
	arr[1] = arr[k] = arr[l] = true;
	for(int i=2;i<=1000000;i++)
	{
		if(i!=k && i!=l)
		{	
			bool win = true;
			win = win && arr[i-1];
			if(i-k>=0)
			{
				win = win && arr[i-k];
			}
			if(i-l >= 0)
			{
				win = win && arr[i-l];
			}
			if(!win)
				arr[i] = true;
		}
	}
	for(int i=0;i<m;i++)
	{
		//scanf("%d",&n);
		n =  readInt();
		if(arr[n])
			putchar_unlocked('A');
		else
			putchar_unlocked('B');
	}
	return 0;
}
