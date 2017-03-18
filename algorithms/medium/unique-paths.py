class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # Time Limit Exceeded
        # if m == 1 or n == 1:
        #     return 1
        # return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
        unique_map = []
        self.init_paths(unique_map)
        return unique_map[m - 1][n - 1]

    def init_paths(self, unique_map):
        unique_map.append([1] * 101)
        for i in range(1, 101):
            l = [1]
            for j in range(1, 101):
                l.append(unique_map[i - 1][j] + l[j - 1])
            unique_map.append(l)


if __name__ == '__main__':
    assert Solution().uniquePaths(3, 6) == 21
    assert Solution().uniquePaths(2, 6) == 6
    assert Solution().uniquePaths(3, 4) == 10
