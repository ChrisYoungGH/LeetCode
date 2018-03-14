/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }

        int count = 0;
        ListNode *right = head;
        while (count < length / 2) {
            right = right->next;
            count++;
        }

        if (length % 2 != 0) {
            right = right->next;
        }

        count = 0;
        ListNode *left = NULL;
        while (count < length / 2) {
            curr = head;
            head = head->next;
            curr->next = left;
            left = curr;
            count++;
        }

        while (left != NULL && right != NULL) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
