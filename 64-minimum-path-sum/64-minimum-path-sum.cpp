class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return minPath(grid,dp,0,0);
        
    }
    
    int minPath(vector<vector<int>>& grid,vector<vector<int>>&dp,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int m=grid.size();
        int n=grid[0].size();
                
        if(i>m-1 || j>n-1)
            return 1e9;
        
        if(i==m-1 && j==n-1)
            return grid[i][j];
        
        return dp[i][j]= min( grid[i][j]+minPath(grid,dp,i+1,j),
                    grid[i][j]+minPath(grid,dp,i,j+1));
        
    }
};