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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Deque<TreeNode> queue1 = new ArrayDeque<TreeNode>();
        Deque<Integer> queue2 = new ArrayDeque<Integer>();

        queue1.add(root);
        queue2.add(1);

        int currDepth = 0;
        while (!queue1.isEmpty() && !queue2.isEmpty()) {
            TreeNode node = queue1.poll();
            currDepth = queue2.poll();

            if (node.left != null) {
                queue1.add(node.left);
                queue2.add(currDepth + 1);
            }

            if (node.right != null) {
                queue1.add(node.right);
                queue2.add(currDepth + 1);
            }
        }

        return currDepth;
    }

    public itn maxDepth2(TreeNode root) {
        return root == null ? 0 : 1 + Math.max(maxDepth2(root.left), maxDepth2(root.right));
    }
}
