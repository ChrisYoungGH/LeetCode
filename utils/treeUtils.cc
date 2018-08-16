#include <iostream>

#include "utils.h"
#include "treeUtils.h"

using namespace std;

// create Tree from array
TreeNode* createTree(int *arr, int n) {
    TreeNode **nodes = new TreeNode*[n];

    for (int i = 0; i < n; i++) {
        TreeNode *&node = nodes[i];
        if (arr[i] != null) {
            node = new TreeNode(arr[i]);
        }
        else {
            node = NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        int leftId = i * 2 + 1;
        int rightId = i * 2 + 2;

        TreeNode *&node = nodes[i];
        if (!node) {
            continue;
        }
        
        if (leftId < n) {
            node->left = nodes[leftId];
        }
        if (rightId < n) {
            node->right = nodes[rightId];
        }
    }
    
    return nodes[0];
}


// create Tree from vector
TreeNode* createTree(vector<int> &vec) {
	int n = vec.size();
    TreeNode **nodes = new TreeNode*[n];

    for (int i = 0; i < n; i++) {
        TreeNode *&node = nodes[i];
        if (vec[i] != null) {
            node = new TreeNode(vec[i]);
        }
        else {
            node = NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        int leftId = i * 2 + 1;
        int rightId = i * 2 + 2;

        TreeNode *&node = nodes[i];
        if (!node) {
            continue;
        }
        
        if (leftId < n) {
            node->left = nodes[leftId];
        }
        if (rightId < n) {
            node->right = nodes[rightId];
        }
    }
    
    return nodes[0];
}

void preorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

void postorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}


// display a Tree
void displayTree(TreeNode *root) {
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}

// destroy a Tree
void destroyTree(TreeNode *root) {
	if (!root) {
	    return;
	}

	destroyTree(root->left);
	destroyTree(root->right);

	delete root;
}