//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0] || !m[n-1][n-1])
        return {"-1"};
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string>res;
        dfs(0,0,n,vis,m,"",res);
        
        return res;
        
    }
    
    void dfs(int row,int col,int n,vector<vector<int>>vis,vector<vector<int>>&m,
    string path,vector<string>&res)
    {
        if(m[row][col]==0)
        return;
        
        if(row==n-1 && col==n-1)
        {
            res.push_back(path);
            return;
        }
        
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        string step="URDL";
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
                !vis[nrow][ncol] && m[nrow][ncol]==1)
                {
                    string temp=path;
                    path.push_back(step[i]);
                    dfs(nrow,ncol,n,vis,m,path,res);
                    path.pop_back();
                }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends