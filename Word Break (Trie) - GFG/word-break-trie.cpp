//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
struct TrieNode{
    TrieNode* links[26];
    bool flag;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            links[i]=nullptr;
        }
        flag=false;
    }
    bool containsKey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,TrieNode* node)
    {
        links[ch-'a']=node;
    }
    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
};


class Solution{
    private:
    Trie trie;
    public:
    unordered_map<string,bool>dp;
    bool solve(string s)
    {
        if(s.empty())
        return true;
        
        if(dp.find(s)!=dp.end())
        return dp[s];
    
    
        bool res=false;
        for(int i=1;i<=s.size();i++)
        {
            string prefix=s.substr(0,i);
            if(trie.search(prefix)&&solve(s.substr(i)))
            {
                res=true;
                break;
            }
        }
        return dp[s]=res;
    }
    int wordBreak(string A, vector<string>&B) {
        for(int i=0;i<B.size();i++)
        {
            trie.insert(B[i]);
        }
        int n=A.size();
        return solve(A);
        
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends