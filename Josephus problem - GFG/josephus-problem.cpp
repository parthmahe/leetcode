// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void answer(int k,vector<int>&v,int index)
    {
        if(v.size()==1)
        {
           return;
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        answer(k,v,index);
    }
    int josephus(int n, int k)
    {
       vector<int> v;
       for(int x=1;x<=n;x++)
       {
           v.push_back(x);
       }
       k--;
       answer(k,v,0);
       return v[0];
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends