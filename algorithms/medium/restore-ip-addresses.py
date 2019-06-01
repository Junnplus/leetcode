class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        results = []

        def dfs(s, cur_result):
            if len(cur_result) > 5:
                return
            if s == '' and len(cur_result) == 4:
                results.append('.'.join(cur_result))
            for i in range(1, 4):
                if i > len(s) or (i > 1 and s[0] == '0'):
                    break
                tmp = int(s[:i])
                if tmp > 255:
                    break
                dfs(s[i:], cur_result + [s[:i]])
        dfs(s, [])
        return results


if __name__ == '__main__':
    s = Solution()
    print(s.restoreIpAddresses("010010"))
