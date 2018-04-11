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
    bool isSymmetrical(TreeNode* root) {
    	if (!root) {
    		return true;
    	}

    	queue<TreeNode*> leftq, rightq;
    	leftq.push(root->left);
    	rightq.push(root->right);

    	while (!leftq.empty() && !rightq.empty()) {
    		TreeNode *leftNode = leftq.front();
    		leftq.pop();
    		TreeNode *rightNode = rightq.front();
    		rightq.pop();

    		if (!leftNode && !rightNode) {
    			continue;
    		}

    		if (!leftNode || !rightNode) {
    			return false;
    		}

    		if (leftNode->val != rightNode->val) {
    			return false;
    		}

    		leftq.push(leftNode->left);
    		leftq.push(leftNode->right);
    		rightq.push(rightNode->right);
    		rightq.push(rightNode->left);
    	}

    	return (leftq.empty() && rightq.empty());

    }

};