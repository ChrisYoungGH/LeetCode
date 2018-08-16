#include <iostream>
#include <cstdlib>

#include "listUtils.h"
#include "utils.h"

using namespace std;

ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {

	ListNode *head = new ListNode(-1);
	ListNode *curr1 = list1, *curr2 = list2, *curr = head;

	while (curr1 != NULL && curr2 != NULL) {
		if (curr1->val < curr2->val) {
			curr->next = curr1;
			curr1 = curr1->next;
		}
		else {
			curr->next = curr2;
			curr2 = curr2->next;
		}
		curr = curr->next;
	}

	if (curr1 == NULL) {
		curr->next = curr2;
	}
	else {
		curr->next = curr1;
	}

	curr = head->next;
	delete [] head;

	return curr;
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n == 0) {
		return NULL;
	}

	while (n > 1) {
		vector<ListNode*> tempSortedLists((n+1)/2);
		for (int i = 0; i < n / 2; i++) {
			tempSortedLists[i] = mergeTwoLists(lists[i*2], lists[i*2+1]);
		}
		if (n % 2) {
			tempSortedLists[n/2] = lists.back();
		}

		lists = tempSortedLists;
		n = lists.size();
	}

	return lists[0];

}


int main() {
	int k = 5;

	vector<vector<int> > data(k);
	srand(time(NULL));
	for (int i = 0; i < k; i++) {
		int size = rand() % 10;
		random_init_i(data[i], size, 50, i, true);
	}

	vector<ListNode*> lists(k);
	for (int i = 0; i < k; i++) {
		lists[i] = createList(data[i]);
		
	}

	for (int i = 0; i < k; i++) {
		cout << "list " << i << ": ";
		displayList(lists[i]);
	}

	ListNode *listAll = mergeKLists(lists);
	displayList(listAll);


	// for (int i = 0; i < k; i++) {
	// 	destroyList(lists[i]);
	// }

	return 0;
}