class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
    	if (!root) {
    		return true;
    	}

    	int depth = 0;
    	return IsBalanced(root, depth);
    }

    bool IsBalanced(TreeNode *root, int &depth) {
    	if (!root) {
    		depth = 0;
    		return true;
    	}

    	int leftDepth, rightDepth;
    	if (IsBalanced(root->left, leftDepth) && IsBalanced(root->right, rightDepth)) {
    		if (abs(leftDepth - rightDepth) <= 1) {
	    		depth = max(leftDepth, rightDepth) + 1;
	    		return true;
    		}
    	}

    	return false;
    }
};