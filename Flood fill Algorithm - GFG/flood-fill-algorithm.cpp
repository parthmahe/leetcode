//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        
        int oldColor=image[sr][sc];
        
        while(!q.empty())
        {
           int row=q.front().first;
           int col=q.front().second;
           
           q.pop();
           
           for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    if(delrow*delcol==0)
                    {
                        int nrow=row+delrow;
                        int ncol=col+delcol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    !vis[nrow][ncol] && image[nrow][ncol]==oldColor)
                        {
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                            
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                {
                    image[i][j]=newColor;
                }
            }
        }
        
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends