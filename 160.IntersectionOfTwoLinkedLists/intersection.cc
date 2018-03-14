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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> visit;
        ListNode *curr = headA;
        while (curr) {
            visit.insert(curr);
            curr = curr->next;
        }
        curr = headB;
        while (curr) {
            if (visit.find(curr) != visit.end()) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }


    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *first = headA, *second = headB;
        while (first != second) {
            first = first != NULL ? first->next : headB;
            second = second != NULL ? second->next : headA;
        }

        return first;
    }
};
