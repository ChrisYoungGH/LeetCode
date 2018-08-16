#include <iostream>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if (!head) {
    		return NULL;
    	}

    	ListNode *curr = head, *curr2 = head;
    	for (int i = 0; i < n+1; i++) {
    		if (!curr2) {
    			return head->next;
    		}
    		curr2 = curr2->next;
    	}

    	while (curr2) {
    		curr = curr->next;
    		curr2 = curr2->next;
    	}
        
    	curr->next = curr->next->next;

    	return head;
    }
};

int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.removeNthFromEnd(head, 5);
	displayList(head);

	return 0;
}