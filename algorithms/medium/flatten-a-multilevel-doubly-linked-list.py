
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return
        tail = self._flatten(head)
        return head, tail

    def _flatten(self, head):
        cur = head
        while cur.next or cur.child:
            if cur.child:
                _next = cur.next
                pre = cur.child
                tail = self._flatten(cur.child)
                cur.next = pre
                tail.next = _next
                pre.prev = cur
                cur.child = None
                if _next:
                    _next.prev = tail
                cur = tail
            else:
                cur = cur.next
        return cur


def main():
    l11 = Node(11, None, None, None)
    l12 = Node(12, None, None, None)
    l10 = Node(10, None, None, None)
    l9 = Node(9, None, None, None)
    l8 = Node(8, None, None, None)
    l7 = Node(7, None, None, None)
    l6 = Node(6, None, None, None)
    l5 = Node(5, None, None, None)
    l4 = Node(4, None, None, None)
    l3 = Node(3, None, None, None)
    l2 = Node(2, None, None, None)
    l1 = Node(1, None, None, None)
    l11.next = l12
    l12.prev = l11
    l7.next = l8
    l8.next = l9
    l8.child = l11
    l9.next = l10
    l10.prev = l9
    l9.prev = l8
    l8.prev = l7
    l1.next = l2
    l2.next = l3
    l3.next = l4
    l4.next = l5
    l5.next = l6
    l6.prev = l5
    l5.prev = l4
    l4.prev = l3
    l3.prev = l2
    l2.prev = l1
    l3.child = l7

    s = Solution()
    head, tail = s.flatten(l1)
    while head:
        print(head.val)
        head = head.next

    print()
    while tail:
        print(tail.val)
        tail = tail.prev


if __name__ == '__main__':
    main()
