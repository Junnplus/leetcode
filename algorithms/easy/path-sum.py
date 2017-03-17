# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False

        def dfs(root, s=0):
            if root.left is None and root.right is None:
                if s == sum:
                    dfs.flag = True
                return
            if root and root.left:
                dfs(root.left, root.left.val + s)
            if root and root.right:
                dfs(root.right, root.right.val + s)
        dfs.flag = False
        dfs(root, root.val)
        return dfs.flag


def test():
    t = TreeNode(5,
                 TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))),
                 TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))))
    s = Solution()
    assert True == s.hasPathSum(t, 22)

if __name__ == '__main__':
    test()
