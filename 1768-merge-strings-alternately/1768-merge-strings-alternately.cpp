class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,n=word1.size(),m=word2.size();
        string res="";
        while(i<n && j<m)
        {
            res+=word1[i];
            res+=word2[j];
            i++,j++;
        }
        
        if(i==n && j==m)
            return res;
        
        if(j<m)
        {
            res.insert(res.end(),word2.begin()+j,word2.end());
        }
        else
        {
            res.insert(res.end(),word1.begin()+i,word1.end());
        }
        
        return res;
    }
};