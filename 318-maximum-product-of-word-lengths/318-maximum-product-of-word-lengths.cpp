class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>bitset;
        for(int x=0;x<words.size();x++)
        bitset.push_back(convert(words[x]));
        
        int res=0;
        for(int x=0;x<words.size();x++)
        {
            for(int y=x+1;y<words.size();y++)
            {
                if((bitset[x]&bitset[y])==0)
                  if(words[x].size()*words[y].size()>res)
                      res=words[x].size()*words[y].size();
                
            }
        }
        return res;
        
    }
    
    int convert(string str)
    {
        int res=0;
        for(auto it:str)
        {
            int index=it-'a';
            res|=1<<(index);
        }
        return res;
    }
};