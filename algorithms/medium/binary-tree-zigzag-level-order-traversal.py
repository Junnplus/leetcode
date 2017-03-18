# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        self.traversal(root, 0, ret)
        for i, r in enumerate(ret):
            if i % 2 != 0:
                r.reverse()
        return ret

    def traversal(self, root, deep, ret):
        if root is None:
            return
        if len(ret) <= deep:
            l = [root.val]
            ret.append(l)
        else:
            ret[deep].append(root.val)
        self.traversal(root.left, deep + 1, ret)
        self.traversal(root.right, deep + 1, ret)


if __name__ == '__main__':
    root = TreeNode(3)
    root.left = node1 = TreeNode(9)
    root.right = node2 = TreeNode(20)
    node2.left = TreeNode(15)
    node2.right = TreeNode(7)
    assert Solution().zigzagLevelOrder(root) == [[3], [20, 9], [15, 7]]
