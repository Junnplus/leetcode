# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        ls = []

        def dfs(root, deep=0):
            if deep >= len(ls):
                ls.append([root and root.val])
            else:
                ls[deep].append(root and root.val)
            if root is None:
                return
            dfs(root.left, deep + 1)
            dfs(root.right, deep + 1)
        dfs(root)
        for l in ls:
            le = len(l)
            if le == 1:
                continue
            if l[:le/2] != l[le/2:][::-1]:
                return False
        return True


def test():
    s = Solution()
    t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    assert True != s.isSymmetric(t)
    t = TreeNode(1,
                 TreeNode(2, TreeNode(3), TreeNode(4)),
                 TreeNode(2, TreeNode(4), TreeNode(3)))
    assert True == s.isSymmetric(t)

if __name__ == '__main__':
    test()
