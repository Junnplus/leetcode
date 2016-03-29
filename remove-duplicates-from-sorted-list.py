# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, nt=None):
        self.val = x
        self.next = nt


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = ListNode(None)
        pre.next = head
        cur = head
        head = pre
        dic = {}
        while pre and pre.next:
            if cur and dic.get(cur.val):
                pre.next = cur.next
            else:
                pre = pre.next
                dic[cur.val] = 1
            cur = cur.next
        return head.next


def test():
    head = ListNode(1, ListNode(2, ListNode(1, ListNode(2))))
    Solution().deleteDuplicates(head)
    l = []
    while head:
        l.append(head.val)
        head = head.next
    assert l == [1, 2]

if __name__ == '__main__':
    test()
