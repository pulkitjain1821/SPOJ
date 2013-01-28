#include <stdio.h>
int rev(int x)
{
    int rev=0;
    while(x>0)
     {
         int digit = x%10;
         rev = rev*10 + digit;
         x = x/10;              
     }
    return rev;     
}
int main()
{
  int N;
  scanf("%d",&N);
  int i;
  for(i=0;i<N;i++)
      {
          int a,b;        
          scanf("%d %d",&a,&b);
          printf("%d\n",rev(rev(a)+rev(b)));            
      }  
  return 0;   
}
