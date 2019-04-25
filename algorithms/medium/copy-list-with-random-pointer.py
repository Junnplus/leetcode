class Node(object):
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return
        cur = head
        while cur:
            node = Node(cur.val, cur.next, cur.random)
            cur.next = node
            cur = cur.next.next
        head1 = head.next
        cur = head
        while cur:
            if cur.next.random:
                cur.next.random = cur.next.random.next
            cur = cur.next.next

        pre = head
        cur = head1
        while pre:
            pre.next = pre.next.next
            pre = pre.next
            if cur.next:
                cur.next = cur.next.next
            cur = cur.next
        return head, head1


def main():
    l1 = Node(1, None, None)
    l2 = Node(2, None, None)
    l3 = Node(3, None, None)
    l1.next = l2
    l2.next = l3
    l1.random = l2
    l2.random = l2
    l3.random = l1
    print(id(l1), id(l2), id(l3))
    s = Solution()
    cur = l1
    while cur:
        print(id(cur), cur.val, id(cur.next), id(cur.random), cur.random.val)
        cur = cur.next

    print()

    head, head1 = s.copyRandomList(l1)
    while head1:
        print(id(head1), head1.val, id(head1.random), head1.random.val)
        head1 = head1.next

    cur = head
    print()
    while cur:
        print(id(cur), cur.val, id(cur.next), id(cur.random), cur.random.val)
        cur = cur.next


if __name__ == '__main__':
    main()
