#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}

	if (!root->left && !root->right) {
		return 1;
	}

	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
