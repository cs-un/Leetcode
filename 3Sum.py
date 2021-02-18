from typing import List

class Solution:
    def decrement(self, num, coll:dict):
        print(coll)
        coll[num] -= 1
        if coll[num] == 0:
            del coll[num]
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        uniquenums = {}
        res = []
        for i in nums:
            print(i)
            if i in uniquenums:
                uniquenums[i] += 1
            else:
                uniquenums[i] = 1
        for i in range(len(nums)):
            self.decrement(nums[i], uniquenums)
            for x in range(i+1, len(nums)):
                self.decrement(nums[x], uniquenums)
                if -(nums[i]+nums[x]) in uniquenums:
                    res.append([nums[i], nums[x], uniquenums[-(nums[i]+nums[x])]])
                    self.decrement(-(nums[i]+nums[x]), uniquenums)

        return res