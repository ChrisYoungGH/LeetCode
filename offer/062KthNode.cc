/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode *root, int k) {
    	if (!root || k <= 0) {
    		return NULL;
    	}

    	TreeNode *node;
    	if (root->left) {
    		node = KthNode(root->left, k);
    	}
    	if (node) {
    		return node;
    	}

    	cnt++;
    	if (cnt == k) {
    		return root;
    	}

    	if (root->right) {
    		node = KthNode(root->right, k);
    	}
    	if (node) {
    		return node;
    	}

    	return NULL;
    }

private:
	int cnt = 0;
    
};