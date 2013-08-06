#include<cstdio>
#include<cstdlib>
#include<cmath>
#define pi 3.14159
 
using namespace std;
 
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
    
        else
        {
            double ans = n;
            ans =  ans*ans/2;
            ans = ans/pi;
            ans = round(ans*100)/100; 
            printf("%.2f\n",ans);
        }
    }
 
    return 0;
}
