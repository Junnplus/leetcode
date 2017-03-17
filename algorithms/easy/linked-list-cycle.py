# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        while head:
            if hasattr(head, 'flag'):
                return True
            head.flag = 1
            head = head.next
        return False
