class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=0;
        int count=0;
        int res=INT_MAX;
        while(j<blocks.size())
        {
            if(blocks[j]=='W')
                count++;
            
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k)
            {
                res=min(res,count);
                
                if(blocks[i]=='W')
                    count--;
                i++;
                j++;
                
            }
            
        }
        
        return res;
        

    }
};