//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        ll k2=K2>K1?K2:K1;
        ll k1=K1<K2?K1:K2;
        
        
        priority_queue<ll>pq;
        ll i=0;
        while(i<N)
        {
            pq.push(A[i]);
            if(pq.size()>=k2)
            pq.pop();
            
            i++;
        }
        
        ll res=0;
        while(pq.size()>k1)
        {
            res+=pq.top();
            pq.pop();
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends