#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int gcd(int a, int b)
{
 while(b!=0)
  {int t = b;
  b = a%t;
  a = t;
 }
 return a;
}

int main()
{
 int n;
 scanf("%d",&n); 
 int arr[n];
 scanf("%d",&arr[0]);
 std::set<int> dfs;
 for(int i=1;i<n;i++)
         {
                     scanf("%d",&arr[i]);
                     dfs.insert(arr[i]-arr[i-1]);
         }
  std::set<int>::iterator it;
  /*for(it = dfs.begin();it!=dfs.end();it++)
         printf("%d--",*it);
  */
  it=dfs.begin();
  int tmp = *it;
  while(it!=dfs.end())
  {
   tmp = gcd(tmp,*it);
   //printf("tmp is --%d\n",tmp);
   ++it;
  }
  //tmp = gcd(tmp,*it);
  //printf("gcd of all is %d\n",tmp);
  int ans=0;
  for(int k=0;k<n-1;k++) 
      {
       ans += (arr[k+1] - arr[k])/tmp  -1;
      }    
printf("%d\n",ans);
//system("PAUSE");
return 0;
}










