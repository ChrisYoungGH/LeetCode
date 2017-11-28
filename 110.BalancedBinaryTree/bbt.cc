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
    bool isBalanced(TreeNode* root) {
        return root == NULL || getHeight(root) != -1 ? true : false;
    }

    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int l_left = getHeight(root->left);
        if (l_left == -1) {
            return -1;
        }

        int l_right = getHeight(root->right);
        if (l_right == -1) {
            return -1;
        }

        if (fabs(l_left - l_right) > 1) {
            return -1;
        }

        return max(l_left, l_right) + 1;
    }
};
