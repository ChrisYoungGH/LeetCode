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
    bool hasCycle(ListNode *head) {
        set<ListNode*> visit;
        ListNode *curr = head;
        while (curr) {
            if (visit.find(curr) == visit.end()) {
                visit.insert(curr);
                curr = curr->next;
            }
            else {
                return true;
            }
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode *walker = head, *runner = head;
        while (runner->next != NULL && runner->next->next != NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) {
                return true;
            }
        }
        return false;
    }
};
