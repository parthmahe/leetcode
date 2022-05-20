class Solution {
public:
    
    vector<int> intersection(vector<int>& a, vector<int>& b) {
            vector<int>mp;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n1 = a.size();
        int n2=b.size();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(i>0 && a[i]==a[i-1])
            {
               
                i++;
                 continue;
            }
            if(a[i]<b[j])
            {
                i++;
                
            }
            else if(a[i]>b[j])
            {
                j++;
            }
            else 
            {
                mp.push_back(a[i]);
                i++;j++;
            }
        }
        return mp;

        
    }
};