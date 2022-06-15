class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector<int>res;
        int maxi=0;
        int n=prices.size();
        for(int x=n-1;x>=0;x--)
        {
            maxi=max(maxi,prices[x]);
            res.push_back(maxi);    
        }
        reverse(res.begin(),res.end());
        for(int x=0;x<res.size();x++)
        {
            res[x]-=prices[x];
        }
        
        
        return *max_element(res.begin(),res.end());
    }
};