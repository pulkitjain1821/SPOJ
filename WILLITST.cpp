#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
  long long int num;
	scanf("%lld",&num);
	if(num==0 || num==1)
		printf("TAK");
	else if(!((num)&(num-1)))
		printf("TAK");
	else
		printf("NIE");
	return 0;
}
