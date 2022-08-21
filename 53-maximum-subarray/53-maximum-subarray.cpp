class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>>dp(2,vector<int>(nums.size()+1,-1));
        return maxsum(nums,0,false,dp);
    }
    
    int maxsum(vector<int>&nums,int i,bool mustpick,vector<vector<int>>&dp)
    {
        if(i==nums.size())
            return mustpick?0:-1e5;
        
        if(dp[mustpick][i]!=-1)
            return dp[mustpick][i];
        
        if(mustpick)
            return dp[mustpick][i]=max(0,nums[i]+maxsum(nums,i+1,true,dp));
        
        return dp[mustpick][i]=max(nums[i]+maxsum(nums,i+1,true,dp),maxsum(nums,i+1,false,dp));
        
    }
};