class Solution {
public:
    int countGoodSubstrings(string s) {
       
        int res=0;
        int i=0;
        int j=0;
         
        map<char,int>mp;
        while(j<s.size())
        {
            mp[s[j]]++;
            
            if(j-i+1<3)
                j++;
            
            else if(j-i+1==3)
            {
                if(mp.size()==3)
                    res++;
                
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;
                j++;
                
            }
            
            
        }
        
        return res;
        
    }
};