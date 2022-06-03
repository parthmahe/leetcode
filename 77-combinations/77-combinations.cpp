class Solution {
public:
    void backtrack(vector<int> ip,vector<int> op,int k,vector<vector<int>>&v)
    {
        if(op.size()==k)
        {
            v.push_back(op);return;
        }
        
        if(ip.size()+op.size()>k)
        {
            vector<int> op1=op;
            vector<int>op2=op;
            op2.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            backtrack(ip,op1,k,v);
            backtrack(ip,op2,k,v);
        }
        else
        {
            vector<int>op1=op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            backtrack(ip,op1,k,v);
        }
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> ip;
        for(int x=1;x<=n;x++)
            ip.push_back(x);
        
        vector<int>op;
        vector<vector<int>> res;
        backtrack(ip,op,k,res);
        return res;
        
    }
};