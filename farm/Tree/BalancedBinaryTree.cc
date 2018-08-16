#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define null INT_MIN

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

void display(TreeNode *node) {
    cout << "Preorder: ";
    preorder(node);
    cout << endl;

    cout << "Inorder: ";
    inorder(node);
    cout << endl;

    cout << "Postorder: ";
    postorder(node);
    cout << endl;
}

TreeNode* build_tree(std::vector<int> vec) {
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

void free_tree(TreeNode *root) {
    if (!root) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    delete root;
}

int getHeight(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = getHeight(root->right);
    if (rightHeight == -1) {
        return -1;
    }

    int diff = abs(leftHeight - rightHeight);
    if (diff > 1) {
        return -1;
    }
    return max(leftHeight, rightHeight) + 1;
}


bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }
    return getHeight(root) != -1;
}


int main() {
    int a[] = {1,2,2,3,null,null,3,4,null,null,4};
    vector<int> va(a, a + sizeof(a) / sizeof(int));
    TreeNode *root = build_tree(va);

    display(root);

    cout << isBalanced(root) << endl;

    free_tree(root);

    return 0;
}