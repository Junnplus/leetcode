class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        for i, key in enumerate(x):
            if x[-i-1] != key:
                return False
        return True
