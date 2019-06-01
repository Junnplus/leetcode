from queue import Queue


class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

    def __repr__(self):
        return str(self.val)


class Solution:
    def averageOfLevels(self, root: TreeNode):
        q = Queue()
        result = []
        q.put(root)
        while not q.empty():
            nsum = 0
            size = q.qsize()
            for _ in range(size):
                n = q.get()
                nsum += n.val
                if n.left:
                    q.put(n.left)
                if n.right:
                    q.put(n.right)
            result.append(nsum / size)
        return result


if __name__ == '__main__':
    root = TreeNode(10, TreeNode(5), TreeNode(15, TreeNode(6), TreeNode(20)))
    print(Solution().averageOfLevels(root))
