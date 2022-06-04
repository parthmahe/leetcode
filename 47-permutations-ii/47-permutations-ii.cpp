class Solution {
public:
    void backtrack(int index,vector<int>v,set<vector<int>>&st)
    {
        if(index==v.size()-1)
        {
            st.insert(v);return;
        }
        
        for(int x=index;x<v.size();x++)
        {
            swap(v[index],v[x]);
            backtrack(index+1,v,st);
            swap(v[index],v[x]);
        }
            
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>v;
        set<vector<int>>s;
        backtrack(0,nums,s);
        for(auto it:s)
            v.push_back(it);
        return v;
        
    }
};