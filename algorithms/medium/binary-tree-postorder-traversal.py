# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.result = []
        self.postorder_traversal(root)
        return self.result

    def postorder_traversal(self, node):
        if node is None:
            return
        self.postorder_traversal(node.left)
        self.postorder_traversal(node.right)
        self.result.append(node.val)
