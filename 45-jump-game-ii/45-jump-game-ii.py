class Solution:
    def jump(self, nums: List[int]) -> int:
        s=d=0
        sl=len(nums)-1
        if(sl==0):
            return(0)
        for i in range(len(nums)-1,-1,-1):
            if(nums[i]>=d):
                sl=i
            d+=1
        sl+=1
        if(sl==0):
            return(1)
        s+=1
        s+=self.jump(nums[:sl])
        return(s)
