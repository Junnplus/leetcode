class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        i = j = 0
        if (not matrix) or (matrix and not matrix[0]):
            return []
        m, n = len(matrix), len(matrix[0])
        ret = []
        f = 1
        while True:
            ret.append(matrix[i][j])
            if i == m - 1 and j == n - 1:
                return ret
            if f == 0:
                if j == 0:
                    f = 1
                    if i == m - 1:
                        j += 1
                    else:
                        i += 1
                elif i == m - 1:
                    f = 1
                    j += 1
                else:
                    j -= 1
                    i += 1
            elif f == 1:
                if i == 0:
                    f = 0
                    if j == n - 1:
                        i += 1
                    else:
                        j += 1
                elif j == n - 1:
                    f = 0
                    i += 1
                else:
                    j += 1
                    i -= 1


if __name__ == '__main__':
    inp = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    assert Solution().findDiagonalOrder(inp) == [1, 2, 4, 7, 5, 3, 6, 8, 9]
