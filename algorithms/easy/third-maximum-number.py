class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return nums[0] if nums[0] > nums[1] else nums[1]
        first_max = -float('Inf')
        second_max = -float('Inf')
        third_max = -float('Inf')
        for n in nums:
            if n > first_max:
                first_max, second_max, third_max = n, first_max, second_max
            elif n > second_max and n != first_max:
                second_max, third_max = n, second_max
            elif n > third_max and n != second_max and n != first_max:
                third_max = n
        if third_max == -float('Inf'):
            return first_max
        return third_max


if __name__ == '__main__':
    assert Solution().thirdMax([2, 2, 3, 1]) == 1
    assert Solution().thirdMax([2, 2, 3]) == 3
    assert Solution().thirdMax([3, 3, 3]) == 3
