//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    void SwapSort(vector<int>&nums)
    {
        int i=0;
        while(i<nums.size())
        {
            int correctPos=nums[i]-1;
            if(correctPos>=nums.size())
            {
                swap(nums[i],nums[nums.size()-1]);
                i++;
            }
            
            else if(correctPos!=i)
            {
                swap(nums[correctPos],nums[i]);
            }
            
            
            else
            i++;
        }
    }
  
  
    int missingNumber(vector<int>& array, int n) {
        SwapSort(array);
        
        for(int i=0;i<n;i++)
        {
            if(i+1!=array[i])
            return i+1;
        }
        
        return n;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends