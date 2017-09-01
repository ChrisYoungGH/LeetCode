# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        currLength = 0
        nextLength = 1
        level = [0] * nextLength

        queue = deque()
        queue.append(root)

        # 每层往栈里存，最后依次弹出
        res = []

        while queue:
            # 层索引为0即为填满，输出这一层，同时更新缓存区
            if currLength == 0:
                res.append(level)
                level = [0] * nextLength
                currLength = nextLength
                nextLength = 0

            # 弹出当前节点并记录到层中
            node = queue.popleft()
            level[-currLength] = node.val
            currLength -= 1

            # 加入左右孩子，并增加下一层长度
            if node.left:
                queue.append(node.left)
                nextLength += 1
            if node.right:
                queue.append(node.right)
                nextLength += 1

        res.append(level)

        return res[:0:-1]
