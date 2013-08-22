#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
 int t;
 scanf ("%d",&t);
 while(t>0)
 {
           t--;
           int s,i,j;
           scanf ("%d",&s);
           int a[s];
           for(i=0;i<s;i++)
           {
                           scanf("%d",&a[i]);
            }
            sort(a,a+s);
            
            int count=0;
            for(i=0;i<s;i++)
            {
                            if(a[i]>0)
                            {
                               for(j=i+1;j<s;j++)
                               {
                                               if (a[j]==2*a[i])
                                               {
                                                                a[j]=0;
                                                                count++;
                                                                break;
                                                }
                                }       
                             }
             }
             printf("%d\n",count);
            
  }   
  return 0;
}
