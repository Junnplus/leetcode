# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        from collections import defaultdict
        node_sum = defaultdict(int)
        self.traverse(root, node_sum)
        node_sum = sorted(node_sum.iteritems(), key=lambda x: x[1], reverse=True)
        return list({s for s, c in node_sum if c == node_sum[0][1]})

    def traverse(self, root, node_sum):
        if root is None:
            return
        self.traverse(root.left, node_sum)
        self.traverse(root.right, node_sum)
        root.sum = root.val
        if root.left is not None:
            root.sum += root.left.sum
        if root.right is not None:
            root.sum += root.right.sum
        node_sum[root.sum] += 1


if __name__ == '__main__':
    seq = [5, 2, -3, 1, 5, 2]
    root = TreeNode(5)
    root.left = node1 = TreeNode(2)
    root.right = node2 = TreeNode(-3)
    node1.left = TreeNode(1)
    node1.right = TreeNode(5)
    node2.left = TreeNode(2)
    assert Solution().findFrequentTreeSum(root) == set([1, 2, 5, 8, 12, -1])
