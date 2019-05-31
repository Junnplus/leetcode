# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        lst = []

        def dfs(root, deep):
            if not root:
                return
            if len(lst) <= deep:
                lst.append([])
            lst[deep].append(root.val)
            # print(root.val)
            dfs(root.left, deep+1)
            dfs(root.right, deep+1)
        dfs(root, 0)
        return lst[::-1]


def test():
    t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    s = Solution()
    assert s.levelOrderBottom(t) == [[3], [9, 20], [15, 7]]


if __name__ == '__main__':
    test()
