class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        for(int x=prices.size()-1;x>=0;x--)
        {
            maxi=max(maxi,prices[x]);
            prices[x]=abs(prices[x]-maxi);    
        }
        
        return *max_element(prices.begin(),prices.end());
    }
};