#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (l1 != NULL && l2 != NULL) {
            int val = 0;
            if (l1->val < l2->val) {
                val = l1->val;
                l1 = l1->next;
            }
            else {
                val = l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        while (l1 != NULL) {
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }

        return head->next;
    }
};
