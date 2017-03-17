# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        root.d = 0
        l = []

        def bfs(root):
            import Queue
            q = Queue.Queue()
            q.put(root)
            while not q.empty():
                e = q.get()
                if e:
                    try:
                        l[e.d].append(e.val)
                    except:
                        l.append([e.val])
                    if e.left:
                        e.left.d = e.d + 1
                    if e.right:
                        e.right.d = e.d + 1
                    q.put(e.left)
                    q.put(e.right)
        bfs(root)
        return l


def test():
    t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    s = Solution()
    l = s.levelOrder(t)
    assert l == [[3], [9, 20], [15, 7]]

if __name__ == '__main__':
    test()
