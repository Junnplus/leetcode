# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max_count = -1

        def dfs(node, count):
            if node is None:
                return
            if count > self.max_count:
                self.max_count = count
            if node.left is not None:
                dfs(node.left, count + 1)
            if node.right is not None:
                dfs(node.right, count + 1)
        dfs(root, 0)
        return self.max_count + 1
