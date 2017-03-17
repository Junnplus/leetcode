class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        length = len(bin(num)) - 2
        return num ^ (2 ** length - 1)


if __name__ == '__main__':
    assert Solution().findComplement(10) == 5
