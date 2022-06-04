class Solution {
public:
   
    void backtrack(vector<int>ip,vector<int>op,int index,vector<vector<int>>&v)
    {
        if(index==ip.size())
        {
            v.push_back(op);
            return;
        }
         vector<int>op1=op;
         op1.push_back(ip[index]);
         backtrack(ip,op1,index+1,v);
         
        vector<int>op2=op;
            index=upper_bound(ip.begin(),ip.end(),ip[index])-ip.begin();
        backtrack(ip,op2,index,v);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        backtrack(nums,{},0,res);
        return res;
    }
};