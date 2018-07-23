#include <iostream>

using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* node) {
        
        if (!node) {
            return NULL;
        }

        //如果有右子树，则找右子树的最左节点
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }

        //没右子树，则找第一个当前节点是父节点左孩子的节点
        else {
            while (node->next) {
                if (node == node->next->left) {
                    return node->next;
                }
                node = node->next;
            }
        }

        return NULL;
    }
};


int main() {
    int arr[] = {8,6,10,5,7,9,11};
    int n = sizeof(arr) / sizeof(int);
    TreeLinkNode *nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeLinkNode(arr[i]);
    }
    nodes[0]->left = nodes[1], nodes[0]->right = nodes[2], nodes[0]->next = NULL;
    nodes[1]->left = nodes[3], nodes[1]->right = NULL, nodes[1]->next = nodes[0];
    nodes[2]->left = NULL,     nodes[2]->right = nodes[5], nodes[2]->next = nodes[0];
    nodes[3]->left = NULL,     nodes[3]->right = nodes[4], nodes[3]->next = nodes[1];
    nodes[4]->left = NULL,     nodes[4]->right = NULL,     nodes[4]->next = nodes[3];
    nodes[5]->left = nodes[6], nodes[5]->right = NULL,     nodes[5]->next = nodes[2];
    nodes[6]->left = NULL,     nodes[6]->right = NULL,     nodes[6]->next = nodes[5];

    Solution s = Solution();

    for (int i = 0; i < 7; i++) {
        TreeLinkNode *nextNode = s.GetNext(nodes[i]);
        cout << nodes[i]->val << ": " << (nextNode ? nextNode->val : -1) << endl;
    }

    return 0;
}