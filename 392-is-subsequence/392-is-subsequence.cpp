class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int res=solve(s,t,n,m);
        if(res!=n)
            return false;
        else
            return true;
    }
    
    int solve(string X,string Y,int n,int m)
    {
        if(n==0||m==0)
            return 0;
            
        if(X[n-1]==Y[m-1])
        {
            return 1+solve(X,Y,n-1,m-1);     
        }
        else
        {
            return solve(X,Y,n,m-1);
        }
    }
};