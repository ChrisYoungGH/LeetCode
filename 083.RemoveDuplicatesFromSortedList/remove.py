# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        prev = head
        curr = head.next
        while curr:
            if curr.val != prev.val:
                prev.next = curr
                prev = prev.next
            curr = curr.next
        prev.next = None

        return head

def printList(head):
    curr = head
    while curr:
        print(curr.val, end=' ')
        curr = curr.next
    print()


if __name__ == '__main__':
    head = ListNode(0)
    arr = [1,1]
    curr = head
    for i in arr:
        curr.next = ListNode(i)
        curr = curr.next
    head = head.next
    printList(head)
    printList(Solution().deleteDuplicates(head))
