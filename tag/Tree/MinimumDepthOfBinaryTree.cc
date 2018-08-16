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


int minDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}
	if (!root->left && !root->right) {
		return 1;
	}
	int ld = 0, rd = 0;
	if (!root->left) {
		return minDepth(root->right) + 1;
	}
	if (!root->right) {
		return minDepth(root->left) + 1;
	}
	return min(minDepth(root->left), minDepth(root->right)) + 1;
}
