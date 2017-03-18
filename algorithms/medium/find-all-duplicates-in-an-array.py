class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        from collections import defaultdict
        ret = []
        once = defaultdict(int)
        for n in nums:
            if once[n]:
                ret.append(n)
            else:
                once[n] += 1
        return ret


if __name__ == '__main__':
    assert Solution().findDuplicates([4,3,2,7,8,2,3,1]) == [2,3]
