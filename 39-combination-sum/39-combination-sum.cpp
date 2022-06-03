class Solution {
public:
    void backtrack(vector<int>ip,vector<int>op,int target,vector<vector<int>>&v)
    {
        if(target==0)
        {
            v.push_back(op);
            return;
        }
        if(target<0||ip.size()==0)
            return;
        
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        backtrack(ip,op2,target-ip[0],v);
        ip.erase(ip.begin());
        backtrack(ip,op1,target,v);
            
    }    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        backtrack(candidates,{},target,res);
        return res;
    }
};