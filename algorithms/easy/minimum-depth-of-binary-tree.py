# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        import sys
        self.min_count = sys.maxint
        if root is None:
            return 0

        def dfs(node, count):
            if node.right is None and node.left is None:
                if count < self.min_count:
                    self.min_count = count
            if node.left:
                dfs(node.left, count + 1)
            if node.right:
                dfs(node.right, count + 1)
        dfs(root, 0)
        return self.min_count + 1
