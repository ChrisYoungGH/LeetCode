class Solution {
public:
    int TreeDepth(TreeNode* root) {
    	return root ? max(TreeDepth(root->left), TreeDepth(root->right)) + 1 : 0;
    }
};