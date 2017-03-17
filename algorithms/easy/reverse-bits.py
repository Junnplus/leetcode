class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        b = bin(n)[2:]
        l = 32 - len(b)
        return int(b[::-1], 2) << l
