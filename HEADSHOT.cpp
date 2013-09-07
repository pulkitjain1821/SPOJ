#include<cstdio>
#include<cstdlib>
using namespace std;

int gcd(int max, int min)
{
	if(max%min==0)
		return min;
	else
		return gcd(min,max%min);
}

int main()
{
	char arr[101];
	char c;
	int len = 0;
	int ones = 0;
	int zeros;
	while(true)
	{
		c = getchar();
		if(c=='\n'||c==EOF)
		{			
			break;		
		}
		else
		{
			arr[len++] = c;
			ones += c - '0';
		}
	}
	arr[len] = '\0';
	
	//printf("Accepted string is %s\n",arr);
	zeros = len - ones;
	int hcf = gcd(len,zeros);
	int lcm = zeros*len/hcf;
	
	//printf("Zeros = %d, Ones = %d, Length = %d\n",zeros,ones,len);
	int shoot = 0;
	int rand  = 0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]=='0')
		{
			shoot += arr[(i+1)%len] - '0';
		}
		rand+= arr[(i+1)%len] - '0';
	}
	shoot = (lcm - (lcm/zeros)*shoot);
	rand  = (lcm - (lcm/len)*rand);
	
	if(shoot==rand)
	{
		printf("EQUAL\n");
	}
	else if(shoot<rand)
	{	
		printf("ROTATE\n");
	}
	else
	{
		printf("SHOOT\n");
	}
	return 0;
}
