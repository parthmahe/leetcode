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
                if((bitset[x]&bitset[y])==0)// wil be zero if all characters are different.
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
            int index=it-'a';// a=0,b=1,c=2 & so on..
            res|=1<<(index); //a=1,b=10,c=100 & abc=111 ((a|b)|c) n so on..
        }
        return res;
    }
};