#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

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

        char *result = new char[res.length()];
        strcpy(result, res.c_str());

        return result;
    }


    TreeNode* Deserialize(char *str) {
        index++;
        int len = strlen(str);
        if (index >= len) {
            return NULL;
        }

        vector<string> strr = split(string(str), ',');
        TreeNode *node = NULL;
        if(strr[index] != "#") {
            node = new TreeNode(atoi(strr[index].c_str()));
            node->left = Deserialize(str);
            node->right = Deserialize(str);
        }

        return node;
    }

    vector<string> split(string str, char ch) {
        vector<string> strr;
        int len = str.length();

        if (len == 0) {
            return strr;
        }

        int begin = 0, end = 0;
        while (end < len) {
            if (str[end] == ch && end >= begin) {
                strr.push_back(str.substr(begin, end-begin));
                begin = end+1;
            }
            end++;
        }

        return strr;
    }

    int index = -1;
};

int main() {
    Solution s = Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    char *serializedTree = s.Serialize(root);
    cout << serializedTree << endl;

    TreeNode *recover = s.Deserialize(serializedTree);
    cout << recover->val << endl;
    cout << recover->left->val << endl;
    cout << recover->right->val << endl;

    return 0;
}