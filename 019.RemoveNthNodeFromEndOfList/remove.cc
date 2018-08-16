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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }

        if (n > len || n <= 0) {
            return head;
        }
        if (n == len) {
            head = head->next;
        }
        else {
            curr = head;
            ListNode *prev;
            int currLen = 0;
            while (currLen < len - n) {
                prev = curr;
                curr = curr->next;
                currLen++;
            }
            prev->next = curr->next;
        }

        return head;
    }
};