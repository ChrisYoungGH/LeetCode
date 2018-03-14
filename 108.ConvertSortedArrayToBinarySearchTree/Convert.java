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
    public TreeNode sortedArrayToBST(int[] nums) {
        return construct(nums, 0, nums.length - 1);
    }

    public TreeNode construct(int[] nums, int low, int high) {

        if (high < low) {
            return null;
        }

        int mid = (low + high) / 2;

        TreeNode root = new TreeNode(nums[mid]);

        root.left = construct(nums, low, mid-1);
        root.right = construct(nums, mid+1, high);

        return root;
    }
}
