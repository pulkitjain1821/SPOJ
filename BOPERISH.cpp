#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        if(t==0)
                break;
        else
            {
             int arr[t];
             for(int i=0;i<t;i++)
                     cin>>arr[i];   
             sort(arr,arr+t);
             int h =0;
             for(int i =t-1;i>=0;i--)
                 {
                  if(arr[i]>=(t-i))
                      h++;
                  else
                      break;             
                 }
             cout<<h<<endl;        
            }               
    }    
    return 0;
}
