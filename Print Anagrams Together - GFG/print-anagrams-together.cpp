//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++
struct TrieNode{
	TrieNode* links[26];
	vector<int> endsWith;

	TrieNode()
	{
		for(int i=0;i<26;i++)
		{
			links[i]=nullptr;
		}
		endsWith={};
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
class Trie{
	private:
	TrieNode *root;
    public:
    Trie(){
    	root=new TrieNode();
    }

    void insert(string &word,int index){
    	TrieNode* node=root;
    	for(int i=0;i<word.size();i++)
    	{
    		if(!node->containsKey(word[i]))
    		{
    			node->put(word[i],new TrieNode());
    		}
    		node=node->get(word[i]);
    	}
    	(node->endsWith).push_back(index);
    }

        vector<int> WordsEqualTo(string word){
    	TrieNode* node=root;
    	for(int i=0;i<word.size();i++)
    	{
    		node=node->get(word[i]);
    	}
    	return node->endsWith;
    }
};
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        Trie trie;
        vector<vector<string>>res;
        vector<string>ls;
        set<string>s;
        for(auto it:string_list)
        {
            ls.push_back(it);
        }
        for(int i=0;i<ls.size();i++)
        {
            sort(begin(ls[i]),end(ls[i]));
            trie.insert(ls[i],i);
            s.insert(ls[i]);
        }
        
        for(auto &it:s)
        {
            vector<int>indices=trie.WordsEqualTo(it);
            ls.clear();
            for(int i=0;i<indices.size();i++)
            {
                ls.push_back(string_list[indices[i]]);
            }
            res.push_back(ls);
            
        }
        
        return res;
    }
        
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends