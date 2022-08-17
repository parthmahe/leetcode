class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
    
    int solve(int n,vector<int>&dp)
    {   
        if(n==0)
            return dp[0]=1;
        if(dp[n]!=-1)
            return dp[n];
        
        int way1=solve(n-1,dp);
        int way2=(n>=2)?solve(n-2,dp):0;
        return dp[n]= way1+way2;
    }
};