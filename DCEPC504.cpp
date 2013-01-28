#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 while(t)
 {
  t--;
  long long int k;
  int n;
  scanf("%d%lld",&n,&k);
  if(n==1)
         {
                        printf("Male\n");
                        continue;
         } 
  if(n>53)
         n=53; 
  while(n>1)
  {
            if(n==2)
                    {
                     if(k==1)
                             printf("Male\n");
                     else
                             printf("Female\n");
                     break;
                    }          
            long long int pw = 1;
            pw = pw<<(n-2) ;
  
            //printf("%d is n and %lld is 2 power n-2 \n",n,pw);
            if(k>pw)
            {
             // printf("----Calculating new k---\n");      
              long long int kp = k - pw;
              //printf("%lld kp---\n",kp);      
              long long int tmp = k - pw;
              //printf("%lld tmp---\n",tmp);
              long long int tmp2 = 1;
              tmp2= tmp2<<(n-3);
              //printf("%lld tmp2---\n",tmp2);
              kp = kp>>(n-3);
              //printf("%lld kp---\n",kp);
              kp = (kp+1)%2;
              //printf("%lld kp---\n",kp);
              kp = kp<<(n-3);
              //printf("%lld kp---\n",kp);
              tmp %= tmp2;
              //printf("%lld tmp---\n",tmp);
              long long int knew =  kp + tmp;   
              //printf("%lld knew---\n",knew);
              if(!knew)
                  {
                       knew = 1;
                       knew = knew<<(n-2);
                  }    
               k=knew;     
              //printf("%lld k ---\n",k);
            }       
            n=n-1;
            //printf("After loop ends---%d--%lld--\n",n,k);
  }
 }
}
 
