# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        _head = head
        while head and head.next:
            head.val, head.next.val = head.next.val, head.val
            head = head.next.next
        return _head


def test():
    head = ListNode(0)
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    head.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    s = Solution()
    s.swapPairs(head)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    assert l == [1, 0, 3, 2, 4]

if __name__ == '__main__':
    test()
