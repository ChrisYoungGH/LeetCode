#include <iostream>
#include <algorithm>
#include <vector>
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

void display(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    cout << node->val << endl;
    display(node->left);
    display(node->right);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currLen = 1, nextLen = 0;
    int flag = 1;
    vector<int> res_level;

    while (!q.empty()) {
        TreeNode *curr = q.front();
        if (flag > 0) {
            res_level.push_back(curr->val);
        }
        else {
            res_level.insert(res_level.begin(), curr->val);
        }
        q.pop();
        currLen--;

        if (curr->left) {
            q.push(curr->left);
            nextLen++;
        }
        if (curr->right) {
            q.push(curr->right);
            nextLen++;
        }

        if (currLen == 0) {
            res.push_back(res_level);
            res_level.resize(0);
            currLen = nextLen;
            nextLen = 0;
            flag = -flag;
        }
    }

    return res;
}


int main() {
    TreeNode *root = new TreeNode(3);
    TreeNode *curr = root;
    curr->left = new TreeNode(9);
    curr->right = new TreeNode(20);
    curr = curr->right;
    curr->left = new TreeNode(15);
    curr->right = new TreeNode(7);

    // display(root);
    vector<vector<int> > res = zigzagLevelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        cout << "level " << i << ": ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}