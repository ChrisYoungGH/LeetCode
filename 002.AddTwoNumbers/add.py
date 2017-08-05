# -*- coding: utf-8 -*-

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # 方法1
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        head = ListNode(0)  # 头节点（虚拟）
        prev = head         # 前一个节点指针
        up = 0              # 进位

        # 相加公共长度部分
        while l1 and l2:
            # 先开辟一个节点
            val = l1.val + l2.val + up
            curr = ListNode(val % 10)
            up = val / 10

            # 前一个节点的next指针指向当前节点，再移动前一个节点指针为当前节点
            prev.next = curr
            prev = curr

            # 移动两个链表指针到下一个节点
            l1 = l1.next
            l2 = l2.next

        # 处理多余的长度，先全部接上，再处理进位
        if l1:
            curr.next = l1
        elif l2:
            curr.next = l2

        # 处理进位，依次加上进位
        while curr.next:
            val = curr.next.val + up
            curr.next.val = val % 10
            up = val / 10
            if up == 0:
                break
            curr = curr.next
        # 最后，如果还有进位，则单独加上
        if up:
            curr.next = ListNode(up)

        return head.next


    # 方法2：模拟竖式运算，每次l1,l2的一位，与进位，三个数字相加，再将和
    # 拆成余数和进位。对于前面的多的空位，用0进行计算。直到l1,l2的位和进位
    # 都为0停止
    def addTwoNumbers2(self, l1, l2):
        head = curr = ListNode(0)
        carry = 0
        while l1 or l2 or carry:
            v1 = v2 = 0     # 当前位，先设置默认值为0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1 + v2 + carry, 10)

            curr.next = ListNode(val)
            curr = curr.next

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
    a1 = [9,9,9]
    a2 = [2]

    l1 = Util().createList(a1)
    l2 = Util().createList(a2)

    Util().printList(l1)
    Util().printList(l2)

    l = Solution().addTwoNumbers2(l1, l2)
    Util().printList(l)

