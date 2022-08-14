class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size()+1,-1);
        vector<int> dp2(cost.size()+1,-1);
        return min(mincost(cost,cost.size(),dp1),mincost(cost,cost.size()-1,dp2));     
    }
    
    int mincost(vector<int>&cost,int n,vector<int> &dp)
    {
          if(n<1)
            return 0;
        
        if(dp[n-1]!=-1)
            return dp[n-1];
        
      
        return dp[n-1]=min(cost[n-1]+mincost(cost,n-1,dp),
                   cost[n-1]+mincost(cost,n-2,dp));
        
        
    }
};