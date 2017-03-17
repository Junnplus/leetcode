class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        lt = list(t)
        for _s in s:
            lt.remove(_s)
        return lt[0]


if __name__ == '__main__':
    assert Solution().findTheDifference('a', 'aa') == 'a'
