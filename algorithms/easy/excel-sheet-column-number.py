class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum([26 ** i * (ord(c) - 64) for i, c in enumerate(s[::-1])])
