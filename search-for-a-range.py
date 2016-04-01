class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if target not in set(nums):
            return [-1, -1]

        def bs_low(nums, target):
            l, h = 0, len(nums) - 1
            while l <= h:
                m = (l + h) / 2
                if nums[m] >= target:
                    h = m - 1
                else:
                    l = m + 1
            return l

        def bs_high(nums, target):
            l, h = 0, len(nums) - 1
            while l <= h:
                m = (l + h) / 2
                if nums[m] > target:
                    h = m - 1
                else:
                    l = m + 1
            return h
        return [bs_low(nums, target) + 1, bs_high(nums, target) + 1]


def test():
    nums = [1, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 5, 7, 8, 9]
    assert Solution().searchRange(nums, 2) == [2, 9]
    assert Solution().searchRange(nums, 3) == [-1, -1]
    assert Solution().searchRange(nums, 4) == [10, 13]
    assert Solution().searchRange(nums, 5) == [14, 14]

if __name__ == '__main__':
    test()
