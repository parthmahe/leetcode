class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int res=0;
        bool found=false;
        for(int x=s.size()-1;x>=0;x--)
        {
            if(s[x]!=' ')
            {
                found=true;
                    res++;
                }
            
            if(s[x]==' ' and found )
                break;
            
        }
        
        return res;
    }
};