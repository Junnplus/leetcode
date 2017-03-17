# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return []
        odd = []
        even = []
        first = head
        second = head.next
        while first:
            odd.append(first.val)
            if second:
                even.append(second.val)
            first = second and second.next
            second = first and first.next
        return odd + even
