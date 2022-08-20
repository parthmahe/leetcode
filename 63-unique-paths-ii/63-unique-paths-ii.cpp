class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return uniquePaths(grid,dp,0,0);
    }
    
    int uniquePaths(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i>m-1 || j>n-1 || grid[i][j]==1)
            return 0;
        
        if(i==m-1 && j==n-1)
            return 1;
        
        return dp[i][j]=uniquePaths(grid,dp,i+1,j)+uniquePaths(grid,dp,i,j+1);
        
    }
};