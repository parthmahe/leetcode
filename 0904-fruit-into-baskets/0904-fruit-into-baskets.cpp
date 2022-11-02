class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int res=0;
        int i=0;
        int j=0;
        while(j<fruits.size())
        {
            mp[fruits[j]]++;
            
            
            if(mp.size()<=2)
            {
                res=max(res,j-i+1);
                
            }
            
            else if(mp.size()>2)
            {
                 while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    
                    i++;  
                    
                }
                
            }
            
            j++;
            
        }
        
        return res;
    }
};