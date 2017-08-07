/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *prev = head, *curr = head->next;
        while (curr != NULL) {
            if (curr->val != prev->val) {
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        prev->next = NULL;

        return head;
    }
};
