class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        
        return maxmoney(nums,dp,nums.size());
    }
    
    int maxmoney(vector<int>&nums,vector<int>&dp,int n)
    {
       if(n<1)
           return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=max(nums[n-1]+maxmoney(nums,dp,n-2),maxmoney(nums,dp,n-1));
    }
};