# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        inorder = []
        self.traversal(root, inorder)
        return inorder

    def traversal(self, root, inorder):
        if root is None:
            return
        self.traversal(root.left, inorder)
        inorder.append(root.val)
        self.traversal(root.right, inorder)


if __name__ == '__main__':
    root = TreeNode(1)
    root.right = node1 = TreeNode(2)
    node1.left = TreeNode(3)
    print Solution().inorderTraversal(root)
    assert Solution().inorderTraversal(root) == [1, 3, 2]
