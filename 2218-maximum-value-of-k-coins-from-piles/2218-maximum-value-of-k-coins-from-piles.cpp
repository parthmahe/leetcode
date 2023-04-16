class Solution {
public:
    int solve(int idx,int k,vector<vector<int>>&piles,
              vector<vector<int>>&dp)
    {
        if(k==0 || idx>=piles.size())
            return 0;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int currPilesize=piles[idx].size();
        int maxCanpick=min(k,currPilesize);
        
            
        int notpick=solve(idx+1,k,piles,dp);
        int pickedsum=0;
        
        int finalsum=notpick;
        for(int i=0;i<maxCanpick;i++)
        {
            pickedsum+=piles[idx][i];
            int pick=pickedsum+solve(idx+1,k-i-1,piles,dp);
            finalsum=max(finalsum,pick);
        }
        
        return dp[idx][k]=finalsum;
            
        }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int maxCoins) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(maxCoins+1,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int k=1;k<=maxCoins;k++)
            {
                int currPilesize=piles[idx].size();
                int maxCanpick=min(k,currPilesize);


                int notpick=dp[idx+1][k];
                int pickedsum=0;

                int finalsum=notpick;
                for(int i=0;i<maxCanpick;i++)
                {
                    pickedsum+=piles[idx][i];
                    int pick=pickedsum+dp[idx+1][k-i-1];
                    finalsum=max(finalsum,pick);
                }

                dp[idx][k]=finalsum;
            
            }
        }
        
        return dp[0][maxCoins];
    }
};