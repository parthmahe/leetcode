class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int left=0;
        int right=1;
        while(right<nums.size())
        {
            if(nums[right]!=nums[left])
                swap(nums[++left],nums[right]);
            right++;
        }
        return left+1;
    }
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
};