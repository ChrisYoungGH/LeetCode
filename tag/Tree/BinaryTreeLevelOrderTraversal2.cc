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

int getHeight(TreeNode *root) {
	return !root ? 0 : 1 + max(getHeight(root->left), getHeight(root->right));
}

void getLevel(TreeNode *root, vector<vector<int> > &res, int height, int level) {
	if (!root) {
		return;
	}

	res[height - level - 1].push_back(root->val);
	getLevel(root->left, res, height, level+1);
	getLevel(root->right, res, height, level+1);
}

vector<vector<int> > levelOrderBottomRecursive(TreeNode* root) {
    int height = getHeight(root);
    vector<vector<int> > res(height);
    if (height == 0) {
    	return res;
    }

    getLevel(root, res, height, 0);

    return res;
}

vector<vector<int> > levelOrderBottomIterative(TreeNode* root) {
    vector<vector<int> > res;

    if (!root) {
        return res;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    vector<int> res_level;
    while (!q.empty()) {
    	TreeNode *curr = q.front();
    	q.pop();

    	if (curr != NULL) {
    		res_level.push_back(curr->val);

    		if (curr->left) {
    			q.push(curr->left);
    		}
    		if (curr->right) {
    			q.push(curr->right);
    		}
    	}

    	else {
			res.insert(res.begin(), res_level);

    		if (!q.empty()) {
    			res_level.resize(0);
    			q.push(NULL);
    		}
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
	vector<vector<int> > res = levelOrderBottomIterative(root);
	for (int i = 0; i < res.size(); i++) {
		cout << "level " << i << ": ";
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}