import math


class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        power = int(math.log(n, 2))
        return 2 ** power == n
