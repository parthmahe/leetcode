class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res,v1,v2;
        v1=convert(s1);
        v2=convert(s2);
        unordered_map<string,int>mp;
        for(auto it:v1)
            mp[it]++;
        
        for(auto it:v2)
            mp[it]++;
        
        for(auto it:mp)
            if(it.second==1)
                res.push_back(it.first);
        return res;
        
    }
    
    vector<string> convert(string str)
    {
        vector<string>words;
        string stringw="";
        for(int x=0;x<str.length();x++)
        {
            if(str[x]==' '){
                words.push_back(stringw);stringw="";}
            else
                stringw+=str[x];
        }
        words.push_back(stringw);
        return words;
    }
};