class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        _matrix = []
        for i in range(n):
            m = []
            for j in range(n - 1, -1, -1):
                m.append(matrix[j][i])
            _matrix.append(m)
            print m
        for i in range(n):
            matrix[i] = _matrix[i]


if __name__ == '__main__':
    image = [
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 0],
        [2, 3, 4, 5, 6, 7, 8, 9, 0, 1],
        [3, 4, 5, 6, 7, 8, 9, 0, 1, 2],
        [4, 5, 6, 7, 8, 9, 0, 1, 2, 3],
        [5, 6, 7, 8, 9, 0, 1, 2, 3, 4],
        [6, 7, 8, 9, 0, 1, 2, 3, 4, 5],
        [7, 8, 9, 0, 1, 2, 3, 4, 5, 6],
        [8, 9, 0, 1, 2, 3, 4, 5, 6, 7],
        [9, 0, 1, 2, 3, 4, 5, 6, 7, 8],
    ]
    rimage = [
        [9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
        [0, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [1, 0, 9, 8, 7, 6, 5, 4, 3, 2],
        [2, 1, 0, 9, 8, 7, 6, 5, 4, 3],
        [3, 2, 1, 0, 9, 8, 7, 6, 5, 4],
        [4, 3, 2, 1, 0, 9, 8, 7, 6, 5],
        [5, 4, 3, 2, 1, 0, 9, 8, 7, 6],
        [6, 5, 4, 3, 2, 1, 0, 9, 8, 7],
        [7, 6, 5, 4, 3, 2, 1, 0, 9, 8],
        [8, 7, 6, 5, 4, 3, 2, 1, 0, 9],
    ]
    Solution().rotate(image)
    assert image == rimage
