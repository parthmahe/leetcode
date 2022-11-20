class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        
        int res=0;
        int j=cost.size()-1;
        
        while(j>=0)
        {
            if(j==0)
            {
                res+=cost[j];
            }
            else
            {
                res+=cost[j]+cost[j-1];
                
            }
            
            j-=3;
            
        }
        
        return res;
    }
};