#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// using binary search
int index(vector<int> &arr, int val, int offset, int length) {
	vector<int>::iterator lower = find(arr.begin() + offset, arr.begin() + offset + length, val);
	int index = lower - arr.begin();
	return index;
}

TreeNode *build0(vector<int> &inorder, vector<int> &postorder, 
		int i_begin, int p_begin, int length) {
	if (length == 0) {
		return NULL;
	}
	if (length == 1) {
		return new TreeNode(inorder[i_begin]);
	}

	int root_val = postorder[p_begin + length - 1];
	int i_root_index = index(inorder, root_val, i_begin, length);
	int left_length = i_root_index - i_begin;
	int right_length = length - (i_root_index - i_begin) - 1;
	int i_right_begin = i_root_index + 1;
	int p_right_begin = left_length + p_begin;

	TreeNode *root = new TreeNode(root_val);
	root->left = build0(inorder, postorder, i_begin, p_begin, left_length);
	root->right = build0(inorder, postorder, i_right_begin, p_right_begin, right_length);

	return root;
}

TreeNode* buildTree0(vector<int>& inorder, vector<int>& postorder) {
	return build0(inorder, postorder, 0, 0, int(inorder.size()));
}


// using map
TreeNode *build(vector<int>& inorder, vector<int> &postorder,
			int i_begin, int i_end, int p_begin, int p_end,
			unordered_map<int, int> &i_index) {
	if (i_begin > i_end || p_begin > p_end) {
		return NULL;
	}

	int root_val = postorder[p_end];
	int i_root_index = i_index[root_val];
	int length = i_root_index - i_begin;

	TreeNode *root = new TreeNode(root_val);
	root->left = build(inorder, postorder, i_begin, i_root_index - 1, p_begin, p_begin + length - 1, i_index);
	root->right = build(inorder, postorder, i_root_index + 1, i_end, p_begin + length, p_end - 1, i_index);

	return root;
}


TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
	if (postorder.empty()) {
		return NULL;
	}

	unordered_map<int, int> i_index;
	for (int i = 0; i < inorder.size(); i++) {
		i_index[inorder[i]] = i;
	}

	return build(inorder, postorder, 0, int(inorder.size())-1, 0, int(postorder.size())-1, i_index);
}


void display(TreeNode *node) {
	if (node == NULL) {
		return;
	}

	printf("%d ", node->val);
	display(node->left);
	display(node->right);
}

int main() {
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	TreeNode *tree = buildTree(inorder, postorder);
	display(tree);
	return 0;
}