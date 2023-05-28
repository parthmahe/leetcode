//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends
struct TrieNode{
    TrieNode* links[26];
    bool flag;
    int count;

    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            links[i]=nullptr;
        }
        flag=false;
        count=0;
    }

    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,TrieNode* node)
    {
        links[ch-'a']=node;
    }
    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
};

int countDistinctSubstring(string s)
{
    int res=1;
    TrieNode* root=new TrieNode();
    for(int i=0;i<s.size();i++)
    {
        TrieNode* node=root;
        for(int j=i;j<s.size();j++)
        {
            if(!node->containsKey(s[j]))
            {
                res++;
                node->put(s[j],new TrieNode());
            }
            node=node->get(s[j]);
        }
    }
    
    return res;
    
}