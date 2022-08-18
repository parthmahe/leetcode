class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        multimap<int,vector<int>>mp;
        
        for(int x=0;x<points.size();x++)
        {
            
            int dist=points[x][0]*points[x][0]+ points[x][1]*points[x][1];
            mp.insert({dist,points[x]});
        }
        
        int count=0;
        for(auto it:mp)
        {
            if(count==k)
                break;
            
            res.push_back(it.second);
            count++;
        }
        
        return res;
    }
};