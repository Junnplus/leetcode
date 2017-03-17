# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        l = [None]
        cursor = head
        while cursor:
            l.append(cursor)
            cursor = cursor.next
        for i in range((n - m + 1)/2):
            l[i + m].val, l[n - i].val = l[n - i].val, l[i + m].val
        return head


def test():
    s = Solution()
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    head = s.reverseBetween(n1, 1, 4)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    print l
    assert l == [4, 3, 2, 1]


if __name__ == '__main__':
    test()
