class Solution {
public:
    string longestPalindrome(string s) {
  
        int start=0;
        int end=0;
        
        for(int i=0;i<s.size();i++)
        {
            int len1=ExpandfromMiddle(s,i,i);
            int len2=ExpandfromMiddle(s,i,i+1);
            
            int len=max(len1,len2);
            
            if(len>(end-start+1))
            {
                start=i-(len-1)/2;
                end=i+(len/2);
            }
        }
        
        return s.substr(start,end-start+1);
    }
    
    int ExpandfromMiddle(string s,int L,int R)
    {
        if(L>R)
            return 0;
        
        while(L>=0 && R<s.size() && s[L]==s[R])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
};