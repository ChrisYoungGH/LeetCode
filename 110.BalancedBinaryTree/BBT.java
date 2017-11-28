/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return root == null ? true : (getHeight(root) == -1 ? false : true);
    }

    public int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left == null && root.right == null) {
            return 1;
        }

        int lLeft = getHeight(root.left);
        if (lLeft == -1) {
            return -1;
        }

        int lRight = getHeight(root.right);
        if (lRight == -1) {
            return -1;
        }

        if (Math.abs(lLeft - lRight) > 1) {
            return -1;
        }

        return Math.max(lLeft, lRight) + 1;
    }
}
