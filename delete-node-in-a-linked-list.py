# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        while node and node.next:
            node.val = node.next.val
            if node.next.next is None:
                node.next = None
            node = node.next


def test():
    head = ListNode(0)
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n5 = ListNode(5)
    head.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    s = Solution()
    s.deleteNode(n2)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    assert l == [0, 1, 3, 4, 5]

if __name__ == '__main__':
    test()
