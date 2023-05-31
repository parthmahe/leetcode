//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> lis(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<int>dp(n,1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	           if(nums[i]>nums[j])
	           {
	               dp[i]=max(dp[i],dp[j]+1);
	           }
	        }
	    }
	    return dp;
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n=nums.size();
	    vector<int>rev(begin(nums),end(nums));
	    reverse(begin(rev),end(rev));
	    vector<int>dp1=lis(nums);
	    vector<int>dp2=lis(rev);
	    
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        res=max(res,dp1[i]+dp2[n-i-1]-1);
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends