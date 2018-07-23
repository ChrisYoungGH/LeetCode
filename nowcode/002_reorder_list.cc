/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "listUtils.h"
#include "utils.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }

        ListNode *curr = slow;
        stack<ListNode*> s;
        while (curr) {
        	s.push(curr);
        	curr = curr->next;
        }

        ListNode *dummy = new ListNode(-1);
        curr = head;
        ListNode *reorder_curr = dummy;
        while (curr != slow && !s.empty()) {
        	reorder_curr->next = curr;
        	curr = curr->next;
        	reorder_curr = reorder_curr->next;
        	reorder_curr->next = s.top();
        	s.pop();
        	reorder_curr = reorder_curr->next;
        }

        if (!s.empty()) {
        	reorder_curr->next = s.top();
        	reorder_curr = reorder_curr->next;
        }

        reorder_curr->next = NULL;

        delete dummy;
    }
};

int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	s.reorderList(head);
	displayList(head);

	return 0;
}