/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 每次找到中间节点作为根, 递归构建左右子树
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	return listToBSTCore(head, NULL);
    }

    TreeNode *listToBSTCore(ListNode *head, ListNode *tail) {
    	if (head == tail) {
    		return NULL;
    	}

    	ListNode *slow = head, *fast = head;
    	while (fast != tail && fast->next != tail) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	TreeNode *root = new TreeNode(slow->val);
    	root->left = listToBSTCore(head, slow);
    	root->right = listToBSTCore(slow->next, tail);

    	return root;
    }
};