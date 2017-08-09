# Definition for a binary tree node.
import Queue

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # 递归方法
    def isSymmetricRecursive(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        return self.isMirrorEqual(root.left, root.right)

    def isMirrorEqual(self, p, q):
        if not p and not q:
            return True

        if not p or not q:
            return False

        if p.val != q.val:
            return False

        l_eq_r = self.isMirrorEqual(p.left, q.right)
        r_eq_l = self.isMirrorEqual(p.right, q.left)

        return l_eq_r and r_eq_l

    # 非递归方法
    def isSymmetricNonRecursive(self, root):
        if not root:
            return True

        leftQueue = Queue.Queue(); rightQueue = Queue.Queue()
        leftTree = root.left; rightTree = root.right

        leftQueue.put(leftTree)
        rightQueue.put(rightTree)

        while not leftQueue.empty() and not rightQueue.empty():
            leftTree = leftQueue.get()
            rightTree = rightQueue.get()

            if not leftTree and not rightTree:
                continue

            if not leftTree or not rightTree:
                return False

            if leftTree.val != rightTree.val:
                return False

            leftQueue.put(leftTree.left)
            leftQueue.put(leftTree.right)

            rightQueue.put(rightTree.right)
            rightQueue.put(rightTree.left)

        if not leftQueue.empty() or not rightQueue.empty():
            return False
        return True
