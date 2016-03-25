import math


class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        power = int(round(math.log(n, 3)))
        return 3 ** power == n
