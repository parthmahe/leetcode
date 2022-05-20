class Solution {
public:
    int mySqrt(int x) {
        
        long long low=0;
        long long high=x;
        long long mid;
        while(low<=high)
        {
             mid=low+(high-low)/2;
            if(mid*mid==(long long)x || mid*mid<(long long)x && (mid+1)*(mid+1)>(long long)x)
                break;
            else if(mid*mid>x)
                high=mid-1;
            else
                low=mid+1;
                
        }
        return mid;
        
    }
};