class Solution {
public:
    // this function searches in the divided arrays
    int BS(int low,int high, vector<int> &nums,int x)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
                return mid;
            else if(x>nums[mid])
                low=mid+1;
            else
                high=mid-1;
            
        }
        return -1;
    }
    
    // this function divides the array in two parts (arr[0]->arr[min-1]),(arr[min]->arr[n-1])
    int search(vector<int>& nums, int target) 
    {
        int N=nums.size();
        int low=0;
        int high=N-1;
        if(nums[low]<=nums[high])
            return BS(low,high,nums,target);
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int prev=(mid+N-1)%N;
            int next=(mid+1)%N;
            
            if(nums[mid]<nums[prev] && nums[mid]<nums[next])
            {
                if(target>=nums[mid]&& target<=nums[N-1])
                    return BS(mid,N-1,nums,target);
                else
                    return BS(0,mid-1,nums,target);
            }
            else if(nums[mid]<nums[high])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
};