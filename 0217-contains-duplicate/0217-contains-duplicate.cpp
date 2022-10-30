class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        bool res=false;
        
        for(auto it:nums)
            mp[it]++;
        
        for(auto it:mp)
        {
            if(it.second>=2)
                res=true;
        }
        
        return res;
            
        
    }
};