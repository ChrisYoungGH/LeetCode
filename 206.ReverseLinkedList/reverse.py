# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        newHead = None
        curr = head
        while curr:
            prev = curr
            curr = curr.next
            prev.next = newHead
            newHead = prev
        return newHead
