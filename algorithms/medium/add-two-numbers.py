# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, nt=None):
        self.val = x
        self.next = nt


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = l1
        flag = 0
        pre = ListNode(None)
        pre.next = l1
        while l1 or l2:
            if l1 and l2:
                val = l1.val + l2.val + flag
                l1.val = val % 10
            elif l1:
                val = l1.val + flag
                l1.val = val % 10
            elif l2:
                val = l2.val + flag
                l = ListNode(val % 10)
                pre.next = l
            flag = val / 10
            pre = pre and pre.next
            l1 = l1 and l1.next
            l2 = l2 and l2.next
        while flag:
            pre.next = ListNode(flag % 10)
            pre = pre.next
            flag /= 10
        return head


def test():
    l1 = ListNode(1, ListNode(2, ListNode(3)))
    l2 = ListNode(1, ListNode(2))
    head = Solution().addTwoNumbers(l1, l2)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    print l
    assert l == [2, 4, 3]
    l1 = ListNode(12, ListNode(3123, ListNode(12)))
    l2 = ListNode(123, ListNode(21))
    head = Solution().addTwoNumbers(l1, l2)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    print l
    assert l == [5, 7, 7, 2, 3]

if __name__ == '__main__':
    test()
