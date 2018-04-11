class Solution {
public:
    ListNode* Merge(ListNode* head1, ListNode *head2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        
        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        
        curr->next = head1 ? head1 : head2;
        
        curr = dummy->next;
        delete dummy;
        
        return curr;
    } 
};