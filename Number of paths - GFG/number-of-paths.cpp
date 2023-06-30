//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


int dp[11][11];
long long numWays(int i,int j,int m, int n)
{
    if(i==m-1 && j==n-1)
    return 1;
    
    if(i>=m)
    return 0;
    
    if(j>=n)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    return dp[i][j]=numWays(i+1,j,m,n)+numWays(i,j+1,m,n);
}

long long  numberOfPaths(int m, int n)
{
    memset(dp,-1,sizeof(dp));
    return numWays(0,0,m,n);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends