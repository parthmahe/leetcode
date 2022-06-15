class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L=0;
        int R=0;
        while(R<nums.size())
        {
            if(nums[R]!=0)
            {
                swap(nums[L],nums[R]);
                L++;
            }
            R++;
        }
    }
};