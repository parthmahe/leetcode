class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low=1;
        long long high=num;
        while(low<=high)
        {
             long long mid=low+(high-low)/2;
             if(mid*mid==(long long)num)
                 return true;
            else if(mid*mid>(long long)num)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};