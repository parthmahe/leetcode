class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return countPath(m,n,dp,0,0);   
    }
    
    int countPath(int m,int n,vector<vector<int>>&dp,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i>m-1 || j>n-1)
            return 0;
        
        if(i==m-1 && j==n-1)
            return 1;
        
        return dp[i][j]= countPath(m,n,dp,i+1,j)+countPath(m,n,dp,i,j+1);
    }
        
};