class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        s = ''.join(S.upper().split('-'))[::-1]
        length = len(s)
        i = 0
        ret = []
        while i < length:
            ret.append(s[i:i + K])
            i += K
        return '-'.join(ret)[::-1]


if __name__ == '__main__':
    assert Solution().licenseKeyFormatting("2-4A0r7-4k", 3) == "24-A0R-74K"
    assert Solution().licenseKeyFormatting("2-4A0r7-4k", 4) == "24A0-R74K"
    assert Solution().licenseKeyFormatting("2-4A0r7-4k", 2) == "24-A0-R7-4K"
    assert Solution().licenseKeyFormatting("2-4A0r7-4k", 5) == "24A-0R74K"
