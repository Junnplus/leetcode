class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ret = []
        i = 0
        length = len(nums)
        if length == 0:
            return False
        if nums[0] > 0:
            f = 1
        else:
            f = 0
        while True:
            if f and nums[i] < 0:
                return False
            elif not f and nums[i] > 0:
                return False
            if ret and i == ret[0]:
                return True
            if len(ret) > len(nums):
                return False
            ret.append(i)
            i = (i + nums[i]) % length


if __name__ == '__main__':
    assert Solution().circularArrayLoop([2, -1, 1, 2, 2]) is True
    assert Solution().circularArrayLoop([-1, 2]) is False
