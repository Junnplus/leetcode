class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        # 理论上这个没有优化代码的时间复杂度是O(N^2)
        import copy
        from random import choice
        seq = []
        nums = copy.deepcopy(self.nums)
        while nums:
            n = choice(nums)
            seq.append(n)
            nums.remove(n)
        return seq

    def _shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        # 理论上这个优化之后的时间复杂度是O(N)
        # 但是提交代码显示的时间复杂度却比上面的算法慢
        # 只能归结为随机算法的锅
        import copy
        from random import randint
        nums = copy.deepcopy(self.nums)
        length = len(nums)
        for i in range(length):
            r = randint(i, length - 1)
            nums[i], nums[r] = nums[r], nums[i]
        return nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()


if __name__ == '__main__':
    print Solution([1,2,3,4,5,6,7])._shuffle()
