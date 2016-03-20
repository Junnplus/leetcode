class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return [bin(i)[2:].count('1') for i in range(num+1)]
