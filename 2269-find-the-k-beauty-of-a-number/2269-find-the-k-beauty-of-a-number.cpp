class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        int res=0;
      vector<int> numb;
        
        int cpy=num;
        while(cpy!=0)
        {
            numb.push_back(cpy%10);
            cpy=cpy/10;
        }
        reverse(numb.begin(),numb.end());
        
        int i=0;
        int j=0;
        
        int temp=0;
        while(j<numb.size())
        {
            temp=temp*10+numb[j];
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k)
            {
                if(temp!=0 && num%temp==0)
                    res++;
                
                temp=temp%((int)pow(10,k-1));
                i++;
                j++;
                
            }
            
        }
        
        return res;
        
    }
};