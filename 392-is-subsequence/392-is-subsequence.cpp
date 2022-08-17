class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int res=solve(s,t,n,m,dp);
        if(res!=n)
            return false;
        else
            return true;
    }
    
    int solve(string X,string Y,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0||m==0)
            return dp[n][m]=0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
            
        if(X[n-1]==Y[m-1])
        {
            return dp[n][m]= 1+solve(X,Y,n-1,m-1,dp);     
        }
        else
        {
            return dp[n][m]=solve(X,Y,n,m-1,dp);
        }
    }
};