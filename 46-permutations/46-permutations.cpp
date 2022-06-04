class Solution {
public:
    void backtrack(int index,vector<int>v,vector<vector<int>>&res)
    {
        if(index==v.size()-1)
        {
            res.push_back(v);return;
        }
        
        for(int x=index;x<v.size();x++)
        {
            swap(v[index],v[x]);
            backtrack(index+1,v,res);
            swap(v[index],v[x]);
        }
            
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        backtrack(0,nums,v);
        return v;
        
    }
};