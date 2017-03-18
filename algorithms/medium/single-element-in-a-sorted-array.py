class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 比较恶心，预处理边界问题，下面的递归没有匹配边界
        self.ret = 0
        if len(nums) == 1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[-1] != nums[-2]:
            return nums[-1]
        self.binary_search(0, len(nums), nums)
        return self.ret

    def binary_search(self, l, r, nums):
        center = (r + l - 1) / 2
        if l >= r:
            return
        if center % 2 == 0:
            if center != len(nums) - 1 and nums[center] != nums[center + 1]:
                if center and nums[center] != nums[center - 1]:
                    self.ret = nums[center]
                    return
                self.binary_search(l, center, nums)
            else:
                self.binary_search(center + 1, r, nums)
        else:
            if nums[center] != nums[center - 1]:
                if center and nums[center] != nums[center + 1]:
                    self.ret = nums[center]
                    return
                self.binary_search(l, center, nums)
            else:
                self.binary_search(center + 1, r, nums)


if __name__ == '__main__':
    assert Solution().singleNonDuplicate([1,1,2,3,3,4,4,8,8]) == 2  # noqa
    assert Solution().singleNonDuplicate([3,3,7,7,10,11,11]) == 10  # noqa
    assert Solution().singleNonDuplicate([3,3,7,7,10,10,11]) == 11  # noqa
    assert Solution().singleNonDuplicate([2,3,3,7,7,11,11]) == 2  # noqa
