# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        curr = head
        while l1 and l2:
            if l1.val < l2.val:
                val = l1.val
                l1 = l1.next
            else:
                val = l2.val
                l2 = l2.next
            curr.next = ListNode(val)
            curr = curr.next

        while l1:
            curr.next = ListNode(l1.val)
            curr = curr.next
            l1 = l1.next

        while l2:
            curr.next = ListNode(l2.val)
            curr = curr.next
            l2 = l2.next

        return head.next


class Util(object):
    def createList(self, arr):
        head = ListNode(0)
        prev = head
        for a in arr:
            curr = ListNode(a)
            prev.next = curr
            prev = curr
        return head.next

    def printList(self, arr):
        while arr is not None:
            print arr.val,
            arr = arr.next
        print


if __name__ == '__main__':
    a1 = []
    a2 = [0]

    l1 = Util().createList(a1)
    l2 = Util().createList(a2)
    l = Solution().mergeTwoLists(l1, l2)

    Util().printList(l1)
    Util().printList(l2)

    Util().printList(l)
