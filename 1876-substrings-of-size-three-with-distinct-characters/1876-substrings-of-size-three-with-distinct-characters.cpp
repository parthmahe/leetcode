class Solution {
public:
    int countGoodSubstrings(string n) {
       
        
        int s=n.size();
        int a=0;
        for(int i=1;i<s-1;i++)
        {
            if(n[i]!=n[i-1]&&n[i]!=n[i+1]&&n[i-1]!=n[i+1])
            {
                a++;
            }
        }
        return a;
        
        
        //for any window size of k
        /*int res=0;
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
        
        return res;*/
        
    }
};