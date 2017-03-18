class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # 表示怀疑是中等题
        return sorted(nums, reverse=True)[k - 1]
