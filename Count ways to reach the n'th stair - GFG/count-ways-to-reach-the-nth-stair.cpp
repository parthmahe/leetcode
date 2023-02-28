//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    long long MOD=1e9+7;
     vector<int>dp=vector<int>(10001,-1); 
    int countWays(int n)
    {
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]= (countWays(n-1)%MOD +countWays(n-2)%MOD)%MOD;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends