class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(n,n,"",res);
        return res;
    }
    
    void generate(int open,int close,string op,vector<string>&res)
    {
        if(open==0 && close==0)
        {res.push_back(op);return;}
    
        if(open>0)
        {
            op.push_back('(');
            generate(open-1,close,op,res);
            op.pop_back();
        }
        
        if(close>open)
        {
            op.push_back(')');
            generate(open,close-1,op,res);
            op.pop_back();
        }
        
    }
};