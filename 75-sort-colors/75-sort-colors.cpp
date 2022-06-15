class Solution {
public:
    void swap(int i,int j,vector<int>&nums)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    
    
    void sortColors(vector<int>& nums) {
        int L=0;
        int R=nums.size()-1;
        
        int i=0;
        while(i<=R)
        {
            if(nums[i]==0)
            {
                swap(L,i,nums);
                i++;
                L++;
            }
            else if(nums[i]==2)
            {
                swap(R,i,nums);
                R--;
            }
            else
            {
                i++;
            }
        }
    }
};