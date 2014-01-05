#include<cstdio>
#include<cstdlib>
int inc[1000];
int out[1000];
using namespace std;
void reset(int n)
{
	for(int i=0;i<n;i++)
	{
		inc[i] = out[i] = 0;
	}
}

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
	int t;
	//scanf("%d",&t);
	t = readInt();
	for(int l=0;l<t;l++)
	{
		int n,r;
		bool done = false;
		//scanf("%d%d",&n,&r);
		n = readInt();
		r = readInt();
		reset(n);
		for(int i=0;i<r;i++)
		{
			/*int r1,r2;
			scanf("%d%d",&r1,&r2);
			inc[r2]++;
			out[r1]++;
			*/
			out[readInt()]++;
			inc[readInt()]++;
		}
		for(int i=0;i<n;i++)
		{
			if(inc[i]!=0 && out[i]!=0)
			{
				printf("Scenario #%d: spied\n",l+1);
				done = true;
				break;
			}
		}
		if(!done)
		{
			printf("Scenario #%d: spying\n",l+1);
		}
	}
	return 0;
}
