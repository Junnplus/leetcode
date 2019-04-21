class ListNode(object):
    def __init__(self, x, next=None):
        self.val = x
        self.next = next 


class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        nodes = []
        if not head:
            return []
        while head:
            nodes.append(head.val)
            head = head.next
        l = len(nodes)
        maxs = []
        res = []
        for i in range(l-1, -1, -1):
            if i == l - 1:
                res.append(nodes[i])
                maxs.append(nodes[i])
                continue
            if nodes[i+1] > nodes[i]:
                maxs.append(nodes[i+1])
            else:
                while len(maxs) > 1:
                    if maxs[-1] > nodes[i]:
                        break
                    maxs.pop()
            res.append(maxs[-1])
        res = res[::-1]
        for i in range(l):
            if nodes[i] >= res[i]:
                res[i] = 0
        return res 


def test():
    head = ListNode(2, ListNode(7, ListNode(4, ListNode(3, ListNode(5)))))
    print(Solution().nextLargerNodes(head))

    head = ListNode(1, ListNode(7, ListNode(5, ListNode(1, ListNode(9, ListNode(2, ListNode(5, ListNode(1))))))))
    print(Solution().nextLargerNodes(head))

    head = ListNode(9, ListNode(7, ListNode(6, ListNode(7, ListNode(6, ListNode(9))))))
    print(Solution().nextLargerNodes(head))

if __name__ == '__main__':
    test()
