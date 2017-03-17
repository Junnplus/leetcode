class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        def q_sort(nums, low, high):
            if low >= high:
                return
            l, h = low, high
            key = nums[low]
            while l < h:
                while l < h and nums[h] >= key:
                    h -= 1
                nums[l] = nums[h]
                while l < h and nums[l] <= key:
                    l += 1
                nums[h] = nums[l]
            nums[l] = key
            q_sort(nums, low, l - 1)
            q_sort(nums, l + 1, high)
        q_sort(nums, 0, len(nums) - 1)


def test():
    nums = [0,1,1,1,1,1,2,1,0,0,0,0,1,1,1,0]
    Solution().sortColors(nums)
    assert nums == [0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2]

if __name__ == '__main__':
    test()
