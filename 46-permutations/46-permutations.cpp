class Solution {
public:
    void backtrack(vector<int>ip,vector<int>op,vector<vector<int>>&res,vector<bool> freq)
    {
        if(op.size()==ip.size())
        {
            res.push_back(op);
        }
        
        for(int x=0;x<ip.size();x++)
        {
            if(!freq[x])
            {
                freq[x]=true;
                op.push_back(ip[x]);
                backtrack(ip,op,res,freq);
                op.pop_back();
                freq[x]=false;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        vector<bool>freq(nums.size(),false);
        backtrack(nums,{},v,freq);
        return v;
        
    }
};