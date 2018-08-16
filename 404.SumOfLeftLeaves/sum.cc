#include <iostream>

#include "utils.h"
#include "treeUtils.h"


int getLeftSum(TreeNode *root, int sum, bool leftFlag) {
	if (!root->left && !root->right && leftFlag) {
		sum += root->val;
		return sum;
	}

	if (root->left) {
		sum = getLeftSum(root->left, sum, true);
	}
	if (root->right) {
		sum = getLeftSum(root->right, sum, false);
	}

	return sum;
}

int sumOfLeftLeaves(TreeNode* root) {
	if (!root) {
		return 0;
	}

	return getLeftSum(root, 0, false);
}

int main() {
	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode *root = createTree(data);
	displayTree(root);
	cout << sumOfLeftLeaves(root) << endl;
	destroyTree(root);

	return 0;
}