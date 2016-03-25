class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        d = {}
        while True:
            n = sum(map(lambda x: int(x) ** 2, list(str(n))))
            if d.get(n, False):
                break
            d[n] = 1
        return bool(d.get(1))
