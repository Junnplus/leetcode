# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        l = []
        if root is None:
            return []
        root.d = 0

        def bfs(root):
            import Queue
            q = Queue.Queue()
            q.put(root)
            while not q.empty():
                e = q.get()
                if e:
                    if e.d >= len(l):
                        l.append([e.val])
                    else:
                        l[e.d].append(e.val)
                    if e.left:
                        e.left.d = e.d + 1
                    if e.right:
                        e.right.d = e.d + 1
                    q.put(e.left)
                    q.put(e.right)
        bfs(root)
        return l[::-1]


def test():
    t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    s = Solution()
    l = s.levelOrderBottom(t)
    assert l[::-1] == [[3], [9, 20], [15, 7]]

if __name__ == '__main__':
    test()
