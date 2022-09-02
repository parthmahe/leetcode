class Solution {
public:
    bool isScramble(string s1, string s2) {
        map<string,bool>mp;
        
        return solve(s1,s2,mp);
    }
    
    bool solve(string s1,string s2,map<string,bool> &mp)
    {
        if(s1==s2)
            return true;
        if(s1.size()<=1)
            return false;
        string temp=s1+" "+s2;
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        
        int n=s1.size();
        bool flag=false;
        for(int i=1;i<=n-1;i++)
        {
            if(solve(s1.substr(0,i),s2.substr(n-i,i),mp) && 
               solve(s1.substr(i,n-i),s2.substr(0,n-i),mp)  ||
                
               solve(s1.substr(0,i),s2.substr(0,i),mp) && 
               solve(s1.substr(i,n-i),s2.substr(i,n-i),mp)
               
              )
            {
                flag=true;
                break;
            }
        }
        
        return mp[temp]=flag;
    }
};