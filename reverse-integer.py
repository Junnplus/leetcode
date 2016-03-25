class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        f = 1 if x > 0 else -1
        x = f * int(str(abs(x))[::-1])
        if x >= 2 ** 31 or x < -(2 ** 31):
            return 0
        else:
            return x
