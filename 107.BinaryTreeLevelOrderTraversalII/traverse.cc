/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) {
            return ans;
        }

        int currLength = 0;
        int nextLength = 1;
        vector<int> level;

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> allLevel;
        while (!q.empty()) {
            if (currLength == 0) {
                allLevel.push_back(level);
                level.clear();
                currLength = nextLength;
                nextLength = 0;
            }

            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) {
                q.push(node->left);
                nextLength++;
            }
            if (node->right) {
                q.push(node->right);
                nextLength++;
            }

            currLength--;
        }

        allLevel.push_back(level);

        for (int i = int(allLevel.size())-1; i >= 1; i--) {
            ans.push_back(allLevel[i]);
        }

        return ans;
    }
};
