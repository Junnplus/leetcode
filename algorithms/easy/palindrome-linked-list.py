# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        l = []
        while head:
            l.append(head.val)
            head = head.next
        le = len(l)
        if le == 1:
            return True
        return l[:le/2] == l[-(le/2):][::-1]


def test():
    l = ListNode(1, ListNode(1, ListNode(1)))
    print Solution().isPalindrome(l)
    l = ListNode(1, ListNode(1))
    print Solution().isPalindrome(l)
    l = ListNode(1)
    print Solution().isPalindrome(l)

if __name__ == '__main__':
    test()
