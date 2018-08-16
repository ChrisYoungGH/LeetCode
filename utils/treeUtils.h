#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include <cstdlib>
#include <vector>

#define null -1

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(int *arr, int n);
TreeNode* createTree(vector<int> &vec);

void displayTree(TreeNode *root);

void destroyTree(TreeNode *root);


#endif