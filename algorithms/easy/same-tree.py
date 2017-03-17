# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        def dfs(p, q):
            if p is None and q is None:
                return
            if (p is None and q) or (p and q is None):
                dfs.flag = False
                return
            if p and q and p.val != q.val:
                dfs.flag = False
                return
            dfs(p.left, q.left)
            dfs(p.right, q.right)
        dfs.flag = True
        dfs(p, q)
        return dfs.flag


def test():
    t1 = TreeNode(1,
                  TreeNode(2, TreeNode(4), TreeNode(5)),
                  TreeNode(3, TreeNode(6)))
    t2 = TreeNode(1,
                  TreeNode(2, TreeNode(4), TreeNode(5)),
                  TreeNode(3, TreeNode(6)))
    t3 = TreeNode(1,
                  TreeNode(2, TreeNode(4), TreeNode(5)),
                  TreeNode(3, TreeNode(7)))
    s = Solution()
    assert True == s.isSameTree(t1, t2)
    assert False == s.isSameTree(t1, t3)

if __name__ == '__main__':
    test()
