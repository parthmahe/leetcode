class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low1=0,high1=nums.size()-1,res1=-1;
        int low2=0,high2=nums.size()-1,res2=-1;
        
        while(low1<=high1)
        {
            int mid=low1+(high1-low1)/2;
            if(nums[mid]==target)
            {
                res1=mid;high1=mid-1;
            }
            else if(nums[mid]>target)
            {
                high1=mid-1;
            }
            else
            {
                low1=mid+1;
            }
        }
        
        
        while(low2<=high2)
        {
            int mid=low2+(high2-low2)/2;
            if(nums[mid]==target)
            {
                res2=mid;low2=mid+1;
            }
            else if(nums[mid]>target)
            {
                high2=mid-1;
            }
            else
            {
                low2=mid+1;
            }
        }
        return {res1,res2};
        
    }
};