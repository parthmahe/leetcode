class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if (n > m) {
        return false;
    }
        
        if(solve(s,t,n,m)!=n)
            return false;
        else
            return true;
    }
    
    int solve(string &X,string &Y,int n,int m)
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

/*class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (s1[i - 1] == s2[j - 1]) {
        return  1 + isSubSequence(s1, s2, i - 1, j - 1);
    }
    else {
        return  isSubSequence(s1, s2, i, j - 1);
    }
}
 
public:
    bool isSubsequence(string s, string t) {
         int m = s.size();
    int n = t.size();
    if (m > n) {
        return false;
    }
    if (isSubSequence(s, t, m, n) == m) {
        return true;
    }
    else {
        return false;
    }
    }
};*/
