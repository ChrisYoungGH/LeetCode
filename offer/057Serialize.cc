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
    char* Serialize(TreeNode *root) {    
        stringstream ss;
        string res;

        if (!root) {
            ss << "#,";
        }
        else {
            ss << root->val << ",";
            ss << string(Serialize(root->left));
            ss << string(Serialize(root->right));
        }

        ss >> res;

        return res.c_str();
    }


    TreeNode* Deserialize(char *str) {
        index++;
        int len = strlen(str);
        if (index >= len) {
            return NULL;
        }

        
    }

private:
    index = -1;
};