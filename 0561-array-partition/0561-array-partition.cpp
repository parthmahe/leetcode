class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        
        int i=0;
        while(i<nums.size())
        {
            res+=nums[i];
            i+=2;
        }
        
        return res;
    }
};