#include <stdio.h>
#include <string.h>

int main()
{
    int d;   
    while(scanf("%d",&d))
    {
         if(d==0)
         break;                
         int i;int done =0;                  
         int a[d+1];
         for(i=1;i<=d;i++)
             {
                   scanf("%d",&a[i]);                       
             }                                       
         for(i=1;i<=d;i++)
             {
                   if(a[a[i]]!=i)
                      {
                       printf("not ambiguous\n");
                       done=1;
                       break;          
                      }                       
             }      
         if(done!=1)                          
         printf("ambiguous\n");    
    }    
    return 0;
}
