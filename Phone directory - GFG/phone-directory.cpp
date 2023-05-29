//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    TrieNode* startsWith(string word)
    {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return nullptr;
            }
            node=node->get(word[i]);
        }
        return node;
    }
    void dfs(TrieNode* node,string s,vector<string>&res)
    {
        if(node->isEnd())
        {
            res.push_back(s);
        }
        
        for(int i=0;i<26;i++)
        {
            if(node->links[i]!=nullptr)
            {
                string temp=s;
                temp.push_back('a'+i);
                dfs(node->links[i],temp,res);
            }
        }
        return;
    }
    vector<string>get(string prefix)
    {
        TrieNode* node=startsWith(prefix);
        if(!node)
        {
            return {"0"};
            
        }
        else
        {
            vector<string>res;
            dfs(node,prefix,res);
            return res;
            
        }
    }
    
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie trie;
        for(int i=0;i<n;i++)
        {
            trie.insert(contact[i]);
        }
            
        string prefix="";
        vector<vector<string>>res;
        for(int i=0;i<s.size();i++)
        {
            prefix+=s[i];
            res.push_back(trie.get(prefix));
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends