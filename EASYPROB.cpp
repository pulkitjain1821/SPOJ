#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string str[16];
	str[0] = "2(0)";
	str[1] = "2";
	str[2] = "2(2)";
	str[3] = "2(2+2(0))";
	str[4] = "2(2(2))";
	str[5] = "2(2(2)+2(0))";
	str[6] = "2(2(2)+2)";
	str[7] = "2(2(2)+2+2(0))";
	str[8] = "2(2(2+2(0)))";
	str[9] = "2(2(2+2(0))+2(0))";
	str[10]= "2(2(2+2(0))+2)";
	str[11]= "2(2(2+2(0))+2+2(0))";
	str[12]= "2(2(2+2(0))+2(2))";
	str[13]= "2(2(2+2(0))+2(2)+2(0))";
	str[14]= "2(2(2+2(0))+2(2)+2)";
	str[15]= "2(2(2+2(0))+2(2)+2+2(0))";

	
	while(t>0)
		{
			t--;
			int n;
			cin>>n;
			cout<<n<<"=";
			int last = 15;
			for(int j=15;j>=0;j--)
				{
					int k=1;
					k<<=j;
					if(k&n)
						last = j;
				}

			for(int i=15;i>=0;i--)
				{
					int k=1;
					k<<=i;
					if(k&n)
						{
							cout<<str[i];
							if(i!=last)
								cout<<"+";
						}
				}
			cout<<endl;
		}
	return 0;
}
