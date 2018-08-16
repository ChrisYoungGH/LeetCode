#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

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
        if (vec[i] != -1) {
            node = new TreeNode(vec[i]);
        }
        else {
            node = NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        TreeNode *&node = nodes[i];
        int leftId = i * 2 + 1;
        int rightId = i * 2 + 2;
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


bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main() {
    int a[] = {1,2,1};
    int b[] = {1,1,2};
    vector<int> va(a, a + sizeof(a) / sizeof(int));
    vector<int> vb(b, b + sizeof(b) / sizeof(int));
    TreeNode *p = build_tree(va);
    TreeNode *q = build_tree(vb);

    cout << isSameTree(p, q) << endl;

    free_tree(p);
    free_tree(q);

    return 0;
}