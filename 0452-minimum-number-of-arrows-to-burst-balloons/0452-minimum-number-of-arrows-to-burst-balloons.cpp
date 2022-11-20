class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        
        int res=1;
        int i=0;
        int end=points[i][1];
        
        i=1;
        while(i<points.size())
        {
             if(points[i][0] > end){
                res++;
                end = points[i][1];
            }
            i++;
        }
        
        return res;
        
        
    }
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
};