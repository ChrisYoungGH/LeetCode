#include <iostream>

#include "listUtils.h"
#include "utils.h"

ListNode* reverseKGroup(ListNode* head, int k) {
	if (!head) {
		return head;
	}

	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *split = head;

	ListNode *prev;
	ListNode *curr = head;
	ListNode *next = head->next;

	ListNode *localHead = dummy;
	ListNode *prevLocalHead = head;

	bool condition = true;
	// each reverse k nodes
	while (split && split->next) {
		// find split bound point
		for (int i = 0; i < k; i++) {
			if (!split) {
				condition = false;
				break;
			}
			split = split->next;
		}

		// lenth < k, no reverse
		if (!condition) {
			break;
		}

		// reverse a group nodes
		prev = split;
		while (curr && curr != split) {
			curr->next = prev;
			prev = curr;
			curr = next;
			if (next) {
				next = next->next;
			}
		}

		// add prev tail (before reversing, it is a local head, last split bound, too)
		localHead->next = prev;
		localHead = prevLocalHead;
		prevLocalHead = split;
	}

	head = dummy->next;
	delete [] dummy;

	return head;
}

int main() {
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	ListNode *list = createList(arr);
	displayList(list);
	ListNode *revList = reverseKGroup(list, 3);
	displayList(revList);

	return 0;
}