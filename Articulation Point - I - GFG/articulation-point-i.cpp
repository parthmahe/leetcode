//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int time=0;
    private:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&tin,
    vector<int>&low,vector<int>&mark)
    {
        vis[node]=1;
        tin[node]=low[node]=time;
        time++;
        int child=0;
        for(auto adjnode:adj[node])
        {
            if(adjnode==parent)continue;
            if(!vis[adjnode])
            {
                dfs(adjnode,node,adj,vis,tin,low,mark);
                low[node]=min(low[node],low[adjnode]);
                if(tin[node]<=low[adjnode] && parent!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[adjnode]);
            }
        }
        if(child>1 && parent==-1)
        mark[node]=1;
        
    }
    public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,0);
        vector<int>tin(V);
        vector<int>low(V);
        vector<int>mark(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,-1,adj,vis,tin,low,mark);
        }
        
        vector<int>res;
        for(int i=0;i<V;i++)
        {
            if(mark[i])
            res.push_back(i);
        }
        if(res.size()==0)return {-1};
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends