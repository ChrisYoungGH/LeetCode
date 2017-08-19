# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        visit = {}
        curr = headA
        while curr:
            visit[curr] = 1
            curr = curr.next
        curr = headB
        while curr:
            if curr in visit:
                return curr
            curr = curr.next
        return None


    ## 方法2：O(1) space
    ## 两个指针分别走两个list,如果长度相同，则中间相遇；
    ## 如果长度不同，再接着走另一个，则必在第二次走的时候相遇于交集处
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB:
            return None
        first = headA
        second = headB
        while first != second:
            first = first.next if first else headB
            second = second.next if second else headA
        return first
