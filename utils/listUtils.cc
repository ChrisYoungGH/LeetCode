#include <iostream>

#include "utils.h"
#include "listUtils.h"

using namespace std;

// create list from array
ListNode* createList(int *arr, int n) {
	if (n <= 0) {
		return NULL;
	}

	ListNode *head = new ListNode(-1);
	ListNode *curr = head;
	for (int i = 0; i < n; i++) {
		curr->next = new ListNode(arr[i]);
		curr = curr->next;
	}
	return head->next;
}

// create list from vector
ListNode* createList(vector<int> &arr) {
	int n = arr.size();
	if (n <= 0) {
		return NULL;
	}

	ListNode *head = new ListNode(-1);
	ListNode *curr = head;
	for (int i = 0; i < n; i++) {
		curr->next = new ListNode(arr[i]);
		curr = curr->next;
	}
	return head->next;
}

// create random value list
ListNode *createList(int n, int bound, int random_state, bool sorted) {
	vector<int> arr(n);
	random_init_i(arr, bound, random_state, sorted);
	return createList(arr);
}

// display a list
void displayList(ListNode *head) {
	ListNode *curr = head;
	while (curr != NULL) {
		cout << curr->val << (curr->next != NULL ? "->" : "");
		curr = curr->next;
	}
	cout << endl;
}

// destroy a list
void destroyList(ListNode *head) {
	while (head != NULL) {
		ListNode *curr = head->next;
		delete head;
		head = curr;
	}
}