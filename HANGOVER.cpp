#include <cstdio>
using namespace std;
int main()
{
	float f;
	while(1)
	{
		scanf("%f",&f);
//		printf("%.2f--input\n",f);
		if(f==0.00)
			break;
		float sum = 0.0;
		int x=2;
		while(sum<f)
		{
			sum+= 1.0/x;
			x++;
		}	
		printf("%d card(s)\n",x-2);
	}
	return 0;
}
