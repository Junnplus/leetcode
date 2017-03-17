# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, nt=None):
        self.val = x
        self.next = nt


class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        pre = ListNode(None)
        pre.next = head
        cur = head
        head = pre
        while pre and pre.next:
            if cur.val == val:
                pre.next = cur.next
                cur = cur.next
            else:
                pre = pre.next
                cur = pre and pre.next
        return head.next


def test():
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(3)))))
    Solution().removeElements(head, 3)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    print l
    assert l == [1, 2, 4]

if __name__ == '__main__':
    test()
