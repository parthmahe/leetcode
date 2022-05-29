class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n=nums.size();
        int lastGoodIn=n-1;
        for(int x=n-1;x>=0;x--){
            if(x+nums[x]>=lastGoodIn)
                lastGoodIn=x;
        }
        return lastGoodIn==0;
    }
};