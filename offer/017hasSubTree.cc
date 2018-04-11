class Solution {
public:
    bool HasSubtree(TreeNode* root1, TreeNode* root2) {       
        if (!root1 || !root2) {
            return false;
        }
        
        if (isSub(root1, root2)) {
            return true;
        }
        
        if (HasSubtree(root1->left, root2) || HasSubtree(root1->right, root2)) {
            return true;
        }
        
        return false;
    }
    
    bool isSub(TreeNode* root1, TreeNode *root2) {
        if (!root1 || !root2) {
            return false;
        }
        
        if (root1->val != root2->val) {
            return false;
        }
        
        bool leftFlag = true, rightFlag = true;
        if (root2->left) {
            leftFlag = isSub(root1->left, root2->left);
        }
        if (root2->right) {
            rightFlag = isSub(root1->right, root2->right);
        }
        
        return leftFlag && rightFlag;
    }
};