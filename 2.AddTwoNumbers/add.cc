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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int v1 = 0, v2 = 0;
            if (l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + carry;
            int val = sum % 10;
            carry = sum / 10;

            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return head->next;
    }
};
