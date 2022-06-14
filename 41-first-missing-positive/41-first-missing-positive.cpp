class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int x=0;x<nums.size();x++)
        {
            if(nums[x]<=0)
                nums[x]=0;
        }
        
        //Our solution exists in 1->len(nums)+1
        // to avoid extra space we convert our array into hashset
        
        for(int x=0;x<nums.size();x++)
        {
            int index=abs(nums[x])-1;
            if(index>=0 and index<nums.size())
            {
                 if(nums[index]>0)
                nums[index]=-nums[index];
                else if(nums[index]==0)
                    nums[index]=-1*(nums.size()+1); //so that we dont mark any integer in range 1->len(num) as present
            }
        }
        
        for(int x=1;x<=nums.size();x++)
        {
            if(nums[x-1]>=0)
                return x;
        }
        return nums.size()+1;
    }
};