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


bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    
    if (!root->left && !root->right) {
        return sum == root->val;
    }

    return hasPathSum(root->left, sum - root->val) || 
           hasPathSum(root->right, sum - root->val);
}

int main() {
    int a[] = {5,4,8,11,null,13,4,7,2,null,null,null,null,null,1};
    vector<int> va(a, a + sizeof(a) / sizeof(int));
    TreeNode *root = build_tree(va);

    for (int i = 0; i < 30; i++) {
        bool has = hasPathSum(root, i);
        if (has) {
            cout << i << ":" <<  has << endl;
        }
    }

    // display(root);

    free_tree(root);

    return 0;
}