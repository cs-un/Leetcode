class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = nums[0]
        cursum = 0
        for n in nums:
            cursum+=n
            maxsum = max(cursum, maxsum)
            if cursum < 0:
                cursum = 0
        return maxsum