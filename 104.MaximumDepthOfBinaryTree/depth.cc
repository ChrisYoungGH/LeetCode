/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> queue1;
        queue<int> queue2;

        queue1.push(root);
        queue2.push(1);

        int depth = 0;
        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node = queue1.front();
            queue1.pop();
            depth = queue2.front();
            queue2.pop();

            if (node->left) {
                queue1.push(node->left);
                queue2.push(depth + 1);
            }

            if (node->right) {
                queue1.push(node->right);
                queue2.push(depth + 1);
            }
        }

        return depth;
    }

    int maxDepth2(TreeNode* root) {
        return !root ? 0 : 1 + max(maxDepth2(root->left), maxDepth2(root->right));
    }
};
