class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int x=0;x<nums.size();x++)
        {
            if(mp.count(target-nums[x]))
            {
                return {mp[target-nums[x]],x};
            }
            mp[nums[x]]=x;
        }
        return {-1,-1};
        
    }
};