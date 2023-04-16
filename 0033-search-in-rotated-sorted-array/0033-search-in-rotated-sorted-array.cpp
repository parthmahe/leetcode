class Solution {
public:
    int bs(int low,int high,vector<int> &nums,int target){

        while(low<=high){
            int mid = low + (high -low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int axis(vector<int>nums){
        int low = 0, high = nums.size()-1,n = nums.size();

        while(low<=high){
            int mid = low+( high-low)/2;
            int prev = (mid+n-1)%n;           
            int next = (mid+1)%n;

            if(nums[mid]<nums[prev] && nums[mid]<nums[next]) return mid;

            else if (nums[mid]<nums[high]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums[0]<=nums[nums.size()-1])
            return bs(0,nums.size()-1,nums,target);
        
       int N=nums.size();
       int pivot = axis(nums);
        if(target>=nums[pivot]&& target<=nums[N-1])
            return bs(pivot,N-1,nums,target);
        else
            return bs(0,pivot-1,nums,target);
    
    
    }
};