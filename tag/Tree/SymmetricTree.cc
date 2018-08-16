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

void display(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    cout << node->val << endl;
    display(node->left);
    display(node->right);
}

bool isSymmetric(vector<int> &vec) {
    for (int i = 0; i < vec.size() / 2; i++) {
        if (vec[i] != vec[vec.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }

    vector<int> level;
    queue<TreeNode*> q;
    q.push(root);
    int currLen = 1, nextLen = 0;

    while (!q.empty()) {
        TreeNode *curr = q.front();
        level.push_back(curr ? curr->val : INT_MIN);
        q.pop();
        currLen--;

        if (curr) {
            q.push(curr->left);
            q.push(curr->right);
            nextLen += 2;
        }

        if (currLen == 0) {
            if (!isSymmetric(level)) {
                return false;
            }

            level.resize(0);

            currLen = nextLen;
            nextLen = 0;
        }
    }

    return true;
}


bool isSymmetric2(TreeNode *root) {
    if (!root) {
        return true;
    }

    queue<TreeNode*> leftq, rightq;
    leftq.push(root->left);
    rightq.push(root->right);

    while (!leftq.empty() && !rightq.empty()) {
        TreeNode *left = leftq.front();
        leftq.pop();
        TreeNode *right = rightq.front();
        rightq.pop();

        if (!left && !right) {
            return continue;
        }
        if (!left || !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        leftq.push(left->left);
        leftq.push(left->right);
        rightq.push(right->right);
        rightq.push(right->left);
    }

    return (leftq.empty() && rightq.empty());
}


int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *curr = root;
    curr->left = new TreeNode(2);
    curr->right = new TreeNode(2);
    TreeNode *tmp = curr;
    curr = curr->left;
    curr->right = new TreeNode(3);
    curr = tmp->right;
    curr->right = new TreeNode(3);

    cout << isSymmetric(root) << endl;

    return 0;
}