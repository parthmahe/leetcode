#define ll long long
class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n-3;i++)
        {
            ll newTarget=target-nums[i];
            for(int j=i+1;j<n-2;j++)
            {
                ll currTarget=newTarget-nums[j];
                int start=j+1;
                int end=nums.size()-1;
                while(start<end)
                {
                    if(nums[end]==currTarget-nums[start])
                        s.insert({nums[i],nums[j],nums[start],nums[end]});
                    
                    if(nums[start]+nums[end]<currTarget)
                        start++;
                    else
                        end--;
                }
            }
        }
        
        return vector<vector<int>>(s.begin(),s.end());
        
    }
};