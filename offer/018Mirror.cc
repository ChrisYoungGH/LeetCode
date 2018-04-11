class Solution {
public:
    TreeNode* Mirror(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        
        TreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        Mirror(root->left);
        Mirror(root->right);
        
        return root;
    }
}