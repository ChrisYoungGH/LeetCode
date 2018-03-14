# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import Queue

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        q = []
        q.append(root)

        curr_remain = 1
        next_remain = 0
        min_depth = 0

        while q:
            # 依次弹出队列头
            node = q.pop(0)
            curr_remain -= 1

            # 如果弹出叶子节点，则最小深度为当前计数层数+1
            if not node.left and not node.right:
                return min_depth + 1

            # 依次放入左右节点
            if node.left:
                q.append(node.left)
                next_remain += 1

            if node.right:
                q.append(node.right)
                next_remain += 1

            if curr_remain == 0:
                min_depth += 1
                curr_remain = next_remain
                next_remain = 0

        return min_depth



    def minDepth2(self, root):

        if not root:
            return 0

        q = []
        q.append(root)
        dep = 0

        while q:
            size = len(q)
            dep += 1

            for i in range(size):
                node = q.pop(0)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                    
                if not node.left and not node.right:
                    return dep

        return dep
