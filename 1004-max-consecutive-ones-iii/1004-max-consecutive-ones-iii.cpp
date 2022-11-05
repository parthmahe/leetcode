class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flips=0;
        int i=0,j=0;
        int res=INT_MIN;
        while(j<nums.size())
        {
            if(nums[j]==0)
                flips++;
            
            if(flips<=k)
            {
                res=max(res,j-i+1);
                j++;
            }
            else if(flips>k)
            {
                res=max(res,j-i);
                    
                while(flips>k)
                {
                    if(nums[i]==0)
                        flips--;
                    i++;
                }
                
                j++;
                
            }
            
        }
        
        return res;
    }
};