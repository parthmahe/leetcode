class Solution {
public:
    
    
    void backtrack(vector<int>&ip,vector<int>avail,int n)
    {
            if(n==0)
            {
                sort(ip.begin(),ip.end());
                return;
            }
            
            if(ip[n-1]<ip[n])
            {
                if(avail.size()==0)
                {swap(ip[n-1],ip[n]);return;}
                avail.push_back(ip[n]);
                int temp=ip[n-1];
                int index=upper_bound(avail.begin(),avail.end(),ip[n-1])-avail.begin();
                ip[n-1]=avail[index];
                avail.erase(avail.begin()+index);
                avail.push_back(temp);
                sort(avail.begin(),avail.end());
                for(int x=n,y=0;x<ip.size();x++,y++)
                {
                    ip[x]=avail[y];
                }
                
                
            }
            
            else
            {
                avail.push_back(ip[n]);
                backtrack(ip,avail,n-1);
            }
    }
       
    void nextPermutation(vector<int>& nums) {
        backtrack(nums,{},nums.size()-1);
    }
};