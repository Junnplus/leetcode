# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        l = []
        if root is None:
            return []

        def dfs(root, s=''):
            if root.right is None and root.left is None:
                l.append(s + str(root.val))
            if root.left:
                dfs(root.left, s + str(root.val) + '->')
            if root.right:
                dfs(root.right, s + str(root.val) + '->')
        dfs(root)
        return l


def test():
    s = Solution()
    t = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3))
    l = s.binaryTreePaths(t)
    assert l == ['1->2->5', '1->3']
    t = TreeNode(1)
    l = s.binaryTreePaths(t)
    print l

if __name__ == '__main__':
    test()
