class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=0;
        
        int res=INT_MAX;
        
        while(j<nums.size())
        {
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k)
            {
                res=min(res,nums[i+k-1]-nums[i]);
                i++;
                j++;
            }
        }
        
        return res;
        
        
        
    }
};