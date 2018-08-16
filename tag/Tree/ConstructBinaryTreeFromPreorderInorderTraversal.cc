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


TreeNode *build(vector<int> &preorder, vector<int> &inorder, 
				int p_begin, int p_end, int i_begin, int i_end,
				unordered_map<int, int> &i_index) {
	if (p_begin > p_end || i_begin > i_end) {
		return NULL;
	}

	int root_val = preorder[p_begin];
	int i_root_index = i_index[root_val];

	int l_p_begin = p_begin + 1;
	int l_p_end = p_begin + i_root_index - i_begin;
	int r_p_begin = l_p_end + 1;
	int r_p_end = p_end;
	
	int l_i_begin = i_begin;
	int l_i_end = i_root_index - 1;
	int r_i_begin = i_root_index + 1;
	int r_i_end = i_end;

	TreeNode *root = new TreeNode(root_val);
	root->left = build(preorder, inorder, l_p_begin, l_p_end, l_i_begin, l_i_end, i_index);
	root->right = build(preorder, inorder, r_p_begin, r_p_end, r_i_begin, r_i_end, i_index);

	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> i_index;
    for (int i = 0; i < inorder.size(); i++) {
    	i_index[inorder[i]] = i;
    }

    return build(preorder, inorder, 0, int(preorder.size())-1, 0, int(inorder.size())-1, i_index);
}


void display(TreeNode *node) {
	if (node == NULL) {
		return;
	}

	display(node->left);
	display(node->right);
	printf("%d ", node->val);
}

int main() {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	TreeNode *tree = buildTree(preorder, inorder);
	display(tree);
	return 0;
}