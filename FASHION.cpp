#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 for(int i=0;i<t;i++)
  {
    int n;
    scanf("%d",&n);
    int m[n];
    int w[n];
    for(int k=0;k<n;k++)
            scanf("%d",&m[k]);
    for(int k=0;k<n;k++)
            scanf("%d",&w[k]);
    sort(m,m+n);
    sort(w,w+n);
    int ans=0;
    for(int k=0;k<n;k++)
            ans+=m[k]*w[k];
    printf("%d\n",ans);        
  }
 return 0;
}
