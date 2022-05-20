class Solution {
public:
    
    bool isPresent(vector<int> v,int target)
    {
        sort(v.begin(),v.end());
        int low=0;
        int high=v.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a1=nums1.size()>nums2.size()?nums2:nums1;
        vector<int> a2=nums1.size()>nums2.size()?nums1:nums2;
        int target;
        vector<int>res;
        for(int x=0;x<a1.size();x++)
        {
            target=a1[x];
            if(isPresent(a2,target))
            {
                if(!isPresent(res,target))
                    res.push_back(target);
            }              
        }
        return res;
        
    }
};