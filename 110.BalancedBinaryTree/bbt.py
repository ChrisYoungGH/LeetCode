# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from math import fabs

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        _, flag = self.getHeightAndFlag(root)

        return flag


    def getHeightAndFlag(self, root):
        if not root:
            return 0, True

        if not root.left and not root.right:
            return 1, True

        h_left, flag1 = self.getHeightAndFlag(root.left)
        h_right, flag2 = self.getHeightAndFlag(root.right)

        if fabs(h_left - h_right) > 1:
            return 0, False

        return max(h_left, h_right) + 1, flag1 & flag2
