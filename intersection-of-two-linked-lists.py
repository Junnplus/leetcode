# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        while headA or headB:
            if headA and hasattr(headA, 'flag'):
                return headA
            if headB and hasattr(headB, 'flag'):
                return headB
            if headA == headB:
                return headA
            if headA:
                headA.flag = 1
            if headB:
                headB.flag = 1
            headA = headA and headA.next
            headB = headB and headB.next
        return None


def test():
    a1 = ListNode(1)
    a2 = ListNode(2)
    a3 = ListNode(3)
    a4 = ListNode(4)
    b1 = ListNode(1)
    b2 = ListNode(2)
    b3 = ListNode(3)
    c1 = ListNode(1)
    c2 = ListNode(2)
    c3 = ListNode(3)
    c4 = ListNode(4)
    a1.next = a2
    a2.next = a3
    a3.next = a4
    a4.next = c1
    b1.next = b2
    b2.next = b3
    b3.next = c1
    c1.next = c2
    c2.next = c3
    c3.next = c4
    node = Solution().getIntersectionNode(a1, b1)
    assert node == c1

if __name__ == '__main__':
    test()
