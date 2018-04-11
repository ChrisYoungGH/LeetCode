#include <iostream>

#include "treeUtils.h"
#include "utils.h"

using namespace std;

class Solution {
public:
	TreeNode *Convert(TreeNode *root) {
		if (!root) {
			return NULL;
		}

		TreeNode *head = NULL;
		TreeNode *prev = NULL;
		Convert(root, prev, head);

		return head;
	}

	void Convert(TreeNode *root, TreeNode *&prev, TreeNode *&head) {
		if (root->left) Convert(root->left, prev, head);

		if (prev) prev->right = root;
		if (root) root->left = prev;
		if (!prev) head = root;
		prev = root;

		if (root->right) Convert(root->right, prev, head);
	}
};


int main() {
	vector<int> vec = {};
	TreeNode *root = createTree(vec);
	displayTree(root);

	Solution s = Solution();
	TreeNode *head = s.Convert(root);
	TreeNode *curr = head, *prev = NULL;
	while (curr) {
		cout << curr->val << " ";
		prev = curr;
		curr = curr->right;
	}
	cout << endl;

	curr = prev;
	while (curr) {
		cout << curr->val << " ";
		prev = curr;
		curr = curr->left;
	}
	cout << endl;

	return 0;
}