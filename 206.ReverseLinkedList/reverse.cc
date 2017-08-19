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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL, *curr = head;
        while (curr) {
            ListNode *prev = curr;
            curr = curr->next;
            prev->next = newHead;
            newHead = prev;
        }

        return newHead;
    }
};
