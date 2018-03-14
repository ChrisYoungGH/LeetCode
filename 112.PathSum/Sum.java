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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }

        return calSum(root, 0, sum);
    }


    public boolean calSum(TreeNode node, int pre_sum, int target) {

        int sum = pre_sum + node.val;

        if (node.left == null && node.right == null) {
            if (sum == target) {
                return true;
            }
            return false;
        }

        boolean flag = false;

        if (node.left != null) {
            flag = calSum(node.left, sum, target);
        }

        if (flag == false && node.right != null) {
            flag = calSum(node.right, sum, target);
        }

        return flag;
    }


    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null || (root.left == null && root.right == null)) {
            return root != null && root.val == sum;
        }

        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }
}
