class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(1e4+1,-1);
        
        return jumpcount(nums,0,dp);
        
    }
    
    int jumpcount(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size()-1)
            return 0;
      
        if(dp[i]!=-1)
            return dp[i];
        
        int x=nums[i];
        if(x==0)
            return 1e9;
        
        int res= INT_MAX;
        while(x--)
        {
           
            
            res=min(res,1+jumpcount(nums,i+x+1,dp));
        }
        
        return dp[i]=res;
        
    }
    
    
};