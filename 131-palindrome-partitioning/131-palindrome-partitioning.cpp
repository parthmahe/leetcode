class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>temp;
        solve(s,0,temp,res);
        return res;
    }
    
   void solve(string s,int i,vector<string> &temp,vector<vector<string>>&res)
    {
        if(i==s.size())
        {
            res.push_back(temp);
            return;
        }
        
        
            for(int k=i;k<s.size();k++)
            {
                if(isPalindrome(s.substr(i,k-i+1)))
                {
                    temp.push_back(s.substr(i,k-i+1));
                    solve(s,k+1,temp,res);
                    temp.pop_back();
                }
            }
       return;
       
    }
    
    bool isPalindrome(string s)
    {
        string x=s;
        reverse(x.begin(),x.end());
        
        return s==x;
    }
};