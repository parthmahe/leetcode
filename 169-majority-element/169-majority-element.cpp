class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res;
        for(auto it: nums)
            mp[it]++;
        
        for(auto it:mp)
        {
            if(it.second>nums.size()/2)
            {res= it.first;break;}
        }
        return res;
}};