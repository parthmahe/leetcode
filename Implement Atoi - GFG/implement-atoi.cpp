//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
      int n=str.size();
      int i=0;
      int sign=1;
      if(str[i]=='-')
      {
          sign=-1;
          i++;
      }
      else if(str[i]=='+')
      {
          i++;
      }
      
      int num=0;
      while(i<n)
      {
          if(str[i]<'0' || str[i]>'9')
          return -1;
          
          int dig=str[i]-'0';
          if(num>INT_MAX/10 || num==INT_MAX/10 && dig>INT_MAX%10)
          {
              if(sign==1)return INT_MAX;
              else return INT_MIN;
          }
          num=num*10+dig;
          i++;
      }
      
      return sign*num;
        
        //
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends