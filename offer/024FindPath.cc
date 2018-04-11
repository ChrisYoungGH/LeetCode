class Solution {
public:
	vector<vector<int> > FindPath(TreeNode *root, int expectNum) {
		vector<vector<int> > res;
		if (!root)	 {
			return res;
		}

		vector<int> nodesVal;

		traverse(root, expectNum, res, nodesVal);

		return res;
	}

	void traverse(TreeNode *root, int partialSum, vector<vector<int> >&res, vector<int> &nodesVal) {
		nodesVal.push_back(root->val);

		if (!root->left && !root->right) {
			if (partialSum == root->val) {
				res.push_back(nodesVal);
			}
		}

		if (root->left) {
			traverse(root->left, partialSum - root->val, res, nodesVal);
		}
		if (root->right) {
			traverse(root->right, partialSum - root->val, res, nodesVal);
		}
		
		nodesVal.pop_back();
	}
};