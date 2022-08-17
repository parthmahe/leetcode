class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1)
            return n;
        
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        int maxi=1;
        for(int x=2;x<dp.size();x++)
        {
            if(x%2)
            {
                dp[x]=dp[x/2]+dp[x/2+1];
            }
            else
            {
                dp[x]=dp[x/2];
            }
            maxi=max(maxi,dp[x]);
        }
        return maxi;
    }
};