/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTCore(num, 0, int(num.size())-1);
    }

    TreeNode *sortedArrayToBSTCore(vector<int> &num, int low, int high) {
        if (low > high) {
            return NULL;
        }

        int mid = (low + high) / 2;     // or int mid = (high - low + 1) / 2 + low;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBSTCore(num, low, mid-1);
        root->right = sortedArrayToBSTCore(num, mid+1, high);

        return root;
    }
};