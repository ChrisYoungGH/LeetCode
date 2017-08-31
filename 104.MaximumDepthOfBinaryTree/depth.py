# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
            
        queue1 = deque([])
        queue2 = deque([])

        queue1.append(root)
        queue2.append(1)

        currDepth = 0
        while queue1 and queue2:
            node = queue1.popleft()
            currDepth = queue2.popleft()
            if node.left:
                queue1.append(node.left)
                queue2.append(currDepth + 1)
            if node.right:
                queue1.append(node.right)
                queue2.append(currDepth + 1)

        return currDepth
