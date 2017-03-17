class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        import string
        alphanumeric = string.ascii_letters + string.digits
        s = string.lower(filter(lambda x: x in alphanumeric, s))
        l = len(s)
        for i in range(l / 2):
            if s[i] != s[-i - 1]:
                return False
        return True
