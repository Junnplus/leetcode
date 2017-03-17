class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, v in enumerate(nums):
            if target-v in d:
                return [d[target-v], i+1]
            d[v] = i+1
