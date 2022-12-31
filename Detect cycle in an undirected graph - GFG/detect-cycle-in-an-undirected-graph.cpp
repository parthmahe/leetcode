//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detectCycle(int src,vector<int>adj[],int vis[])
    {
        stack<pair<int,int>>st;
        st.push({src,-1});
        vis[src]=1;
        
        while(!st.empty())
        {
            int node=st.top().first;
            int parent=st.top().second;
            
            st.pop();
            
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    st.push({it,node});
                }
                else if(it!=parent)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i,adj,vis))
                return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends