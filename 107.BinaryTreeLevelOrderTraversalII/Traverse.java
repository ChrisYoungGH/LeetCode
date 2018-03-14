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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }

        int currLength = 0;
        int nextLength = 1;
        List<Integer> level = new ArrayList<Integer>();

        Deque<TreeNode> queue = new ArrayDeque<TreeNode>();
        queue.add(root);

        List<List<Integer>> allLevel = new ArrayList<List<Integer>>();
        while (!queue.isEmpty()) {
            if (currLength == 0) {
                allLevel.add(level);
                level = new ArrayList<Integer>();
                currLength = nextLength;
                nextLength = 0;
            }

            TreeNode node = queue.poll();
            level.add(node.val);
            currLength--;

            if (node.left != null) {
                queue.add(node.left);
                nextLength++;
            }
            if (node.right != null) {
                queue.add(node.right);
                nextLength++;
            }
        }

        allLevel.add(level);

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for (int i = allLevel.size() - 1; i >= 1; i--) {
            ans.add(allLevel.get(i));
        }

        return ans;
    }
}
