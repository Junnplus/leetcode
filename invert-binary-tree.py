# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        def dfs(node):
            if node is None:
                return
            node.left, node.right = node.right, node.left
            if node.left is not None:
                dfs(node.left)
            if node.right is not None:
                dfs(node.right)
        dfs(root)
        return root


def test():
    s = Solution()
    root = TreeNode(0)
    n1 = TreeNode(1)
    n2 = TreeNode(2)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n6 = TreeNode(6)
    n7 = TreeNode(7)
    n8 = TreeNode(8)
    root.left = n1
    root.right = n2
    n1.left = n3
    n1.right = n4
    n2.left = n5
    n2.right = n6
    n5.left = n7
    n5.right = n8
    s.invertTree(root)
    assert root.left == n2
    assert root.right == n1
    assert n1.left == n4
    assert n1.right == n3
    assert n2.left == n6
    assert n2.right == n5
    assert n5.left == n8
    assert n5.right == n7

if __name__ == '__main__':
    test()
