import java.util.*;

public class Tree {
    public boolean isSymmetricRecursive(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isMirrorEqual(root.left, root.right);
    }

    public boolean isMirrorEqual(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }
        boolean l_eq_r = isMirrorEqual(p.left, q.right);
        boolean r_eq_l = isMirrorEqual(p.right, q.left);

        return l_eq_r && r_eq_l;
    }

    public boolean isSymmetricNonRecursive(TreeNode root) {
        if (root == null) {
            return true;
        }
        LinkedList<TreeNode> leftQueue = new LinkedList<TreeNode>();
        LinkedList<TreeNode> rightQueue = new LinkedList<TreeNode>();
        TreeNode leftTree = root.left;
        TreeNode rightTree = root.right;

        leftQueue.add(leftTree);
        rightQueue.add(rightTree);

        while (!leftQueue.isEmpty() && !rightQueue.isEmpty()) {
            leftTree = leftQueue.poll();
            rightTree = rightQueue.poll();

            if (leftTree == null && rightTree == null) {
                continue;
            }

            if (leftTree == null || rightTree == null) {
                return false;
            }

            if (leftTree.val != rightTree.val) {
                return false;
            }

            leftQueue.add(leftTree.left);
            leftQueue.add(leftTree.right);

            rightQueue.add(rightTree.right);
            rightQueue.add(rightTree.left);
        }

        if (!leftQueue.isEmpty() || !rightQueue.isEmpty()){
            return false;
        }

        return true;
    }

    /**
    * Definition for a binary tree node.
    */
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
}
