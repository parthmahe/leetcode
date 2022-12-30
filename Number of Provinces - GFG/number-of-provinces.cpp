//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>ls[V];
        for(int row=0;row<V;row++)
        {
            for(int col=0;col<V;col++)
            {
                if(adj[row][col]==1 && row!=col)
                {
                    ls[row].push_back(col);
                    ls[col].push_back(row);
                }
            }
        }
        
        int provinces=0;
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            { provinces++;
                dfs(vis,ls,i);
                
            }
        }
        
        return provinces;
        
    }
    
    void dfs(int vis[],vector<int>ls[], int node)
    {
        vis[node]=1;
        for(auto it:ls[node])
        {
            if(!vis[it])
            {
                dfs(vis,ls,it);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends