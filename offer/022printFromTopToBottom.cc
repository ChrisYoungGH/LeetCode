class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> res;
		if (!root) {
			return res;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *node = q.front();
			res.push_back(node->val);
			q.pop();

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}

		return res;
	}
};