//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        int scc=0;
        
        vector<int>vis(V,0);
        stack<int>finishtime;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfstime(i,adj,vis,finishtime);
        }
        
        
        vector<int>adjnew[V];
        
        for(int node=0;node<V;node++)
        {   
            vis[node]=0;
            for(auto adjnode:adj[node])
            {
                adjnew[adjnode].push_back(node);
            }
        }
        
         while(!finishtime.empty())
         {
            int node=finishtime.top();
            finishtime.pop();
            if(!vis[node])
            {
                scc++;
                dfs(node,adjnew,vis);
            }
        }
        
        return scc;
    }
    
    void dfstime(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfstime(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends