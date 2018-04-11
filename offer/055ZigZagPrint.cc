/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) {
        	return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        int currLen = 1, nextLen = 0;
        int flag = 1;

        vector<int> level;

        while (!q.empty()) {
        	TreeNode *curr = q.front();
        	if (flag > 0) {
        		level.push_back(curr->val);
        	}
        	else {
        		level.insert(level.begin(), curr->val);
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
        		res.push_back(level);
        		level.clear();
        		currLen = nextLen;
        		nextLen = 0;
        		flag = -flag;
        	}
        }

        return res;
    }
    
};