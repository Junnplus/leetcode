class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l, h = 0, len(nums) - 1
        while l <= h:
            m = (l + h) / 2
            if target <= nums[m]:
                h = m - 1
            else:
                l = m + 1
        return l


def test():
    nums = [1, 3, 5, 6]
    print Solution().searchInsert(nums, 5)
    print Solution().searchInsert(nums, 2)
    print Solution().searchInsert(nums, 7)
    print Solution().searchInsert(nums, 4)
    print Solution().searchInsert(nums, 6)
    print Solution().searchInsert(nums, 0)

if __name__ == '__main__':
    test()
