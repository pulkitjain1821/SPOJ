#include <cstdio>
using namespace std;
int main()
{
 int t;    
 scanf("%d",&t);
 while(t>0)
     {
      t--;
      //printf("%d--t\n",t);
      long long int n;
      scanf("%lld",&n);
      //printf("%d--n\n",n); 
      long long int sum=0;
      long long int x = n;
      while(x>0)
           {
            x--;
            //printf("%d--x\n",x); 
            long long int a;
            scanf("%lld",&a);
            //printf("%d--a\n",a);
            sum+=a;
            sum%=n;
           }
      if(!sum)
          printf("YES\n");
      else
          printf("NO\n");    
     }
 return 0;
}
