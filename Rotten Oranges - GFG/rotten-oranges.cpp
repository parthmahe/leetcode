//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        int tm=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cntFresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        
        int cnt=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            
            tm=max(tm,t);
            
            q.pop();
            
           int delrow[]={-1,0,1,0};
           int delcol[]={0,1,0,-1};
           
           for(int i=0;i<4;i++)
           {
           
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                            
                }
            }
                
        }
        
        if(cntFresh!=cnt)
        return -1;
        
        return tm;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends