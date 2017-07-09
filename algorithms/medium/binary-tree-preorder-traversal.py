# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.result = []
        self.preorder_traversal(root)
        return self.result

    def preorder_traversal(self, node):
        if node is None:
            return
        self.result.append(node.val)
        self.preorder_traversal(node.left)
        self.preorder_traversal(node.right)


def test():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    print(Solution().preorderTraversal(root))


if __name__ == '__main__':
    test()
