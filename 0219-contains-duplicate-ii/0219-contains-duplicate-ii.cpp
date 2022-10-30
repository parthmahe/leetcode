class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      
        map<int,int> mp;
        for(int x=0;x<nums.size();x++)
        {
            if(mp.count(nums[x]))
            {
                if(x-mp[nums[x]]<=k)
                    return true;
            }
            mp[nums[x]]=x;
        }
        
        return false;
        
    }
};