class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++)
            pq.push(stones[i]);
            
        while(!pq.empty())
        {
            if(pq.size()==1)
                return pq.top();
            
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            
            if(x<y)
                y=y-x,pq.push(y);
        }
        
        
        return 0;
    }
};