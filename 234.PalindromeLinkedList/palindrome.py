# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 计算长度
        length = 0
        curr = head
        while curr:
            curr = curr.next
            length += 1

        # 将右指针移到右端开始处
        count = 0
        right = head
        while count < length / 2:
            right = right.next
            count += 1
        # 如果是奇数则要下一位
        if length % 2:
            right = right.next

        # 将左半段反转指针
        left = None
        count = 0
        while count < length / 2:
            curr = head
            head = head.next
            curr.next = left
            left = curr
            count += 1

        # 依次比较左右指针的值
        while left and right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next

        return True


def create(l):
    head = ListNode(0)
    curr = head
    for n in l:
        curr.next = ListNode(n)
        curr = curr.next
    return head.next


if __name__ == '__main__':
    l = [1,0,1]
    head = create(l)
    print Solution().isPalindrome(head)
