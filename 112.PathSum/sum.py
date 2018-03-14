# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        return self.calSum(root, 0, sum)


    def calSum(self, node, pre_sum, target):
        sum = pre_sum + node.val

        if not node.left and not node.right and sum == target:
            return True

        flag = False

        if node.left:
            flag = self.calSum(node.left, sum, target)
        if node.right and flag == False:
            flag = self.calSum(node.right, sum, target)

        return flag


    def hasPathSum(self, root, sum):
        if not root or (not root.left and not root.right):
            return root is not None and root.val == sum

        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
