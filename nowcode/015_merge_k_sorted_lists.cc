#include <iostream>
#include <climits>
#include "utils.h"
#include "listUtils.h"

using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	int n = lists.size();
    	if (!n) {
    		return NULL;
    	}

    	while (n > 1) {
	    	for (int i = 0; i < n / 2; i++) {
				lists[i] = mergeTwoLists(lists[i], lists[i + (n-n/2)]);		// if odd, remain mid
	    	}
    		
    		n = n / 2 + n % 2;
    	}

    	return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
  		ListNode *curr = dummy;
  		while (l1 && l2) {
  			if (l1->val < l2->val) {
  				curr->next = l1;
  				l1 = l1->next;
  			}
  			else {
  				curr->next = l2;
  				l2 = l2->next;
  			}

  			curr = curr->next;
  		}

  		curr->next = l1 ? l1 : l2;

  		ListNode *head = dummy->next;
  		delete dummy;

  		return head;
    }
};

class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if (empty(lists)) {
    		return NULL;
    	}

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;


        while (!empty(lists)) {
        	int min_index = minVal(lists);

        	curr->next = lists[min_index];
        	lists[min_index] = lists[min_index]->next;
        	curr = curr->next;
	        cout << curr->val << endl;
        }

        for (int i = 0; i < lists.size(); i++) {
        	curr->next = lists[i];
        	while (curr->next) {
        		curr = curr->next;
        	}
        }

        ListNode *sortedHead = dummy->next;
        delete dummy;

        return sortedHead;
    }

    bool empty(vector<ListNode *> &lists) {
    	for (int i = 0; i < lists.size(); i++) {
    		if (lists[i]) {
    			return false;
    		}
    	}
    	return true;
    }

    int minVal(vector<ListNode *> &lists) {
    	int min = INT_MAX;
    	int min_index = -1;
    	for (int i = 0; i < lists.size(); i++) {
    		if (lists[i] && lists[i]->val < min) {
    			min_index = i;
    			min = lists[i]->val;
    		}
    	}
    	return min_index;
    }
};


int main() {
	const int m = 10;
	int arr[][m] = {{5,9,11}, {1,7,9,10,12}, {4,5,7,8}};
	int ms[] = {3, 5, 4};
	int n = sizeof(ms) / sizeof(int);

	n = 0;
	vector<ListNode *> lists(n);
	for (int i = 0; i < n; i++) {
		lists[i] = createList(arr[i], ms[i]);
	}

	for (int i = 0; i < n; i++) {
		displayList(lists[i]);
	}

	Solution s = Solution();
	ListNode *head = s.mergeKLists(lists);
	displayList(head);

	return 0;
}