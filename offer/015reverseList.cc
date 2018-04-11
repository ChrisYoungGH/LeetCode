class Solution {
public:
    ListNode* ReverseList(ListNode *head) {
        ListNode *prev = head;
        ListNode *curr = prev ? prev->next : NULL;
        ListNode *next = curr ? curr->next : NULL;
        
        if (prev) {
            prev->next = NULL;
        }
        
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next ? next->next : NULL;
        }
        
        return prev;
    }
};