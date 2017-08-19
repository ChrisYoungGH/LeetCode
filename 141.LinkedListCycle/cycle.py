# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # 方法1：使用标记数组，存已访问节点
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        visit = {}
        curr = head
        while curr:
            if curr not in visit:
                visit[curr] = 1
                curr = curr.next
            else:
                return True
        return False

    # 方法2：一个走路一个跑，如果有环，跑的必追上走的。注意边界判断条件
    def hasCycle2(self, head):
        if not head:
            return False
        walker = runner = head
        while runner.next and runner.next.next:
            walker = walker.next
            runner = runner.next.next
            if walker == runner:
                return True
        return False
