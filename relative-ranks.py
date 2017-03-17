class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        RANK = ['Gold Medal', 'Silver Medal', 'Bronze Medal']
        sorted_nums = sorted(nums)
        length = len(nums)
        ret = []
        for n in nums:
            i = length - sorted_nums.index(n)
            if i <= 3:
                ret.append(RANK[i - 1])
            else:
                ret.append(str(i))
        return ret


if __name__ == '__main__':
    nums = [6, 3, 1, 4, 5, 7, 9]
    print nums
    s = Solution().findRelativeRanks(nums)
    assert s == ['Bronze Medal', '6', '7', '5', '4', 'Silver Medal', 'Gold Medal']
