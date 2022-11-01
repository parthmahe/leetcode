class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int temp=num;
        int res=0;
        int curr=0;
        int pow=1;
        
        while(temp!=0)
        {
            curr+=(temp%10)*pow;
            
            if(--k>0)
            {
                pow=pow*10;
            }
            
            else
            {
                if(curr && !(num%curr))
                    res++;
                
                curr=curr/10;
                
            }
            temp=temp/10;
        }
        return res;
    }
};