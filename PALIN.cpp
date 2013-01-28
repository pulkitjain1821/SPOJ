#include<cstdlib>
#include<iostream>

using namespace std;

string next_palin(string num);
string next_greater(string palin);
int ispalin(string x);
int gr_than(string num1,string num2);
int all_nines(string x);

int main()
{
    int t;
    cin>>t;
    
    string num;
    num.reserve(1000000);
    for(int i=0;i<t;i++)
       {
            cin>>num;
            cout<<next_palin(num)<<endl;
       }    
       
    //system("PAUSE");
    return 0;   
}

string next_palin(string num)
{
    int len = num.length();
    string temp;
           if(len%2==0)       
                              {
                                        string t = num.substr(0,len/2);        
                                        temp = t;                                                                                                    
                                        temp = temp + string(t.rbegin(),t.rend());         
                              }
            else
                              {
                                        string t = num.substr(0,len/2);        
                                        temp = t ;                                                                                                   
                                        temp = temp + num[len/2] + string(t.rbegin(),t.rend());                             
                              }                                                                                                                                                                                 
           string poans = temp;
           while(!(gr_than(poans,num)))
           {
                poans = next_greater(poans);                                                   
           }                            
           return poans;                   
}

int gr_than (string num1,string num2)
{
    int len1 = num1.length();
    int len2 = num2.length();
    if(len1>len2)
                 return 1;
    else if(len1<len2)
                 return 0;
    else
        {
                 for(int i =0;i<len1;i++)
                         if(num1[i]-num2[i]>0)
                                              return 1;
                         else if(num1[i]-num2[i]<0)
                                              return 0;
                 return 0;                             
        }                  
                 
}

string next_greater(string palin)
{
      string ans(palin); 

      int len = palin.length();
      int ptr1 , ptr2;                    
      if(len%2==0)
            {
                  ptr1 = len/2 - 1; 
                  ptr2 = ptr1+1;
                                          
            }
      else
          {
                  ptr1 = ptr2 = len/2;                        
          }
      
      bool done = false;
      while(!done && ptr1>=0 && ptr2<len)
                  {
					  if(palin[ptr1]=='9')
						{
							ans[ptr1]='0';
                            ans[ptr2]='0';
                            ptr1--;
                            ptr2++;
                        }
                      else
						{
							ans[ptr1] = ans[ptr2] = ans[ptr1]+1;
							done = true;
						}
                        
                     /*switch(palin[ptr1])
                                        {
                                          case '0': ans[ptr1]='1';
                                                    ans[ptr2]='1';              
                                                    done = true;
                                                    break;
                                          case '1': ans[ptr1]='2';
                                                    ans[ptr2]='2';
                                                    done = true;              
                                                    break;
                                          case '2': ans[ptr1]='3';
                                                    ans[ptr2]='3';              
                                                    done = true;
                                                    break;
                                          case '3': ans[ptr1]='4';
                                                    ans[ptr2]='4';              
                                                    done = true;
                                                    break;
                                          case '4': ans[ptr1]='5';
                                                    ans[ptr2]='5';              
                                                    done = true;
                                                    break;
                                          case '5': ans[ptr1]='6';
                                                    ans[ptr2]='6';              
                                                    done = true;
                                                    break;
                                          case '6': ans[ptr1]='7';
                                                    ans[ptr2]='7';              
                                                    done = true;
                                                    break;
                                          case '7': ans[ptr1]='8';
                                                    ans[ptr2]='8';              
                                                    done = true;
                                                    break;
                                          case '8': ans[ptr1]='9';
                                                    ans[ptr2]='9';              
                                                    done = true;
                                                    break;
                                          case '9': ans[ptr1]='0';
                                                    ans[ptr2]='0';
                                                    ptr1--;
                                                    ptr2++;
                                                    break;                        
                                         }*/        
                  }
  
  if(ptr1==-1 && ptr2 ==len)
  {
                                ans = '1'+ans;
                                ans[len]='1';
  }
  return ans;
}
