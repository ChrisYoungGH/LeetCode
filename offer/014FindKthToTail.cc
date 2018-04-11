class Solution {
public:
    ListNode *FindKthToTail(ListNode *head, unsigned int k) {
        ListNode *p0, *p1;
        p0 = p1 = head;       
        
        for (int i = 0; i < k; i++) {
            if (!p1) {
                return NULL;
            }
            p1 = p1->next;
        }
        
        while (p1) {
            p0 = p0->next;
            p1 = p1->next;
        }
        
        return k ? p0 : NULL;
    }
};