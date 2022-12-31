//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>s;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]==1)
                    {
                        vector<pair<int,int>>temp;
                        bfs(row,col,vis,grid,temp);
                        s.insert(temp);
                    }
                
            }
        }
        
        return s.size();
    }
    
     void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid, 
     vector<pair<int,int>>&res)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;


        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            res.push_back({(row-i),(col-j)});
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                        int nrow=row+delrow[i];
                        int ncol=col+delcol[i];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                        !vis[nrow][ncol] && grid[nrow][ncol]==1)
                        {
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
            }
        }
    }
        
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends