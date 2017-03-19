# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = 0
        return self.traverse(root, k) or 0

    def traverse(self, root, k):
        if root is None:
            return
        l = self.traverse(root.left, k)
        if l is not None:
            return l
        self.k += 1
        if self.k == k:
            return root.val
        r = self.traverse(root.right, k)
        if r is not None:
            return r


if __name__ == '__main__':
    root = TreeNode(8)
    root.left = node1 = TreeNode(3)
    root.right = node2 = TreeNode(10)
    node1.left = TreeNode(1)
    node1.right = node3 = TreeNode(6)
    node3.left = TreeNode(4)
    node3.right = TreeNode(7)
    node2.right = node4 = TreeNode(14)
    node4.left = TreeNode(13)
    assert Solution().kthSmallest(root, 3) == 4
