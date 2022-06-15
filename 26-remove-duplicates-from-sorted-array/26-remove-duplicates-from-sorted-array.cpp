class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L=0;
        int R=1;
        while(R<nums.size())
        {
            if(nums[R]!=nums[L])
                swap(nums[++L],nums[R]);
            R++;
        }
        return L+1;
    }
};