# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # 1.都为空节点，子树相等
        if not p and not q:
            return True
        # 2.不都为空节点，子树不相等
        if not p or not q:
            return False
        # 3.值不相等，子树不相等
        if p.val != q.val:
            return False
        # 4.左右子树相等才相等
        isSameLeft = isSameRight = True
        isSameLeft = self.isSameTree(p.left, q.left)
        isSameRight = self.isSameTree(p.right, q.right)

        return isSameLeft and isSameRight


class Tree(object):
    def create(self, arr):
        root = TreeNode(arr[0])
        self.createNode(arr, root, 0)
        return root

    def createNode(self, arr, root, index):
        leftIndex = index * 2 + 1
        rightIndex = index * 2 + 2
        if leftIndex < len(arr):
            root.left = TreeNode(arr[leftIndex])
            self.createNode(arr, root.left, leftIndex)
        if rightIndex < len(arr):
            root.right = TreeNode(arr[rightIndex])
            self.createNode(arr, root.right, rightIndex)
        return

    def traverse(self, root):
        if root:
            print root.val
        else:
            print 'None'
        if root.left:
            self.traverse(root.left)
        if root.right:
            self.traverse(root.right)


if __name__ == '__main__':
    root = Tree().create([10,5,null,null,15])
    Tree().traverse(root)
