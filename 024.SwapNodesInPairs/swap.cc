#include <iostream>

#include "listUtils.h"
#include "utils.h"

ListNode *swapPairs(ListNode *head) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *prev= dummy;
	ListNode *first = prev->next;
	if (!first || !first->next) {
		return head;
	}
	ListNode *second = first->next;


	while (prev && first && second) {
		prev->next = second;
		
		ListNode *temp = first;
		first->next = second->next;
		second->next = temp;

		prev = first;
		first = prev->next;
		if (!first || !first->next) {
			break;
		}
		second = first->next;
	}


	head = dummy->next;
	delete [] dummy;

	return head;
}


int main() {

	ListNode *list = createList(7, 100, 1, true);
	displayList(list);
	ListNode *swapList = swapPairs(list);
	displayList(swapList);
	destroyList(list);
	return 0;
}