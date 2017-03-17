# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return
        if head.next is None:
            return head
        pre = ListNode(None)
        pre.next = head
        cur = head
        l = 0
        while cur:
            l += 1
            if cur is not head:
                cur.prev = pre
            cur = cur.next
            pre = pre.next
        cur = pre
        head.prev = cur
        for _ in range(k % l):
            cur.prev.next = None
            cur.next = head
            head = cur
            cur = cur.prev
        return head


def test():
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    head = Solution().rotateRight(head, 4)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    assert l == [2, 3, 4, 5, 1]
    head = ListNode(1)
    head = Solution().rotateRight(head, 4)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    assert l == [1]

if __name__ == '__main__':
    test()
