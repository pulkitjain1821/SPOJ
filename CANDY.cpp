#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n;
 while(1)
         {
          scanf("%d",&n);
          if(n==-1)
                   break;
          int a[n];int sum=0;
          for(int i=0;i<n;i++)
                  {
                              scanf("%d",&a[i]);
                              sum+= a[i];
                  }
          if(sum%n!=0)
                      printf("-1\n");
          else
          {                    
                      sort(a,a+n);
                      //printf("done\n");
                      int k=0;int ans=0;
                      while(a[k]<(sum/n))
                                         {
                                                ans+= (sum/n)-a[k];
                                                k++;
                                         }
                      printf("%d\n",ans);             
          }
         }
 return 0;
}


