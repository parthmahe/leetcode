//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isOperator(char ch)
    {
        switch(ch)
        {
            case '*':
            case '/':
            case '+':
            case '-':
            case '^':
            case '%':
            return true;
        }
        return false;
    }
  public:
    string preToInfix(string s) {
        stack<string>st;
        for(int i=s.size()-1;i>=0;i--)
        {
            
            if(isOperator(s[i]))
            {
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();
                string temp="("+top1+s[i]+top2+")";
                
                st.push(temp);
            }
            else
            {
                st.push(string(1,s[i]));
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends