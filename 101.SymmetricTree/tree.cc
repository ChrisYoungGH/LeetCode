#include <iostream>
#include <queue>
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


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isMirrorEqual(root->left, root->right);
    }

    bool isMirrorEqual(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool l_eq_r = isMirrorEqual(p->left, q->right);
        bool r_eq_l = isMirrorEqual(p->right, q->left);

        return l_eq_r && r_eq_l;
    }

    bool isSymmetricNonRecursive(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> leftQueue, rightQueue;
        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;

        leftQueue.push(leftTree);
        rightQueue.push(rightTree);

        while (!leftQueue.empty() && !rightQueue.empty()) {
            leftTree = leftQueue.front();
            leftQueue.pop();
            rightTree = rightQueue.front();
            rightQueue.pop();

            if (leftTree == NULL && rightTree == NULL) {
                continue;
            }

            if (leftTree == NULL || rightTree == NULL) {
                return false;
            }

            if (leftTree->val != rightTree->val) {
                return false;
            }

            leftQueue.push(leftTree->left);
            leftQueue.push(leftTree->right);

            rightQueue.push(rightTree->right);
            rightQueue.push(rightTree->left);
        }

        if (!leftQueue.empty() || !rightQueue.empty()){
            return false;
        }

        return true;
    }
};
