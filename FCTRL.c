#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fctrl(int n)
{
int count =0; int dsor = 5;// (int)math.power(5,1);
while(n>=dsor)
 {
  count+=  (n/dsor) ;
  dsor = dsor*5; 
  
 }

return count;
}

int main()
{
int T,i;
scanf("%d",&T);
for(i=0;i<T;i++)
 {
  int num;
  scanf("%d",&num);
  printf("%d\n",fctrl(num));
 }
return 0;
}




