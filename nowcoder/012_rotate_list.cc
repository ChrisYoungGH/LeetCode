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
    ListNode *rotateRight(ListNode *head, int k) {
    	// avoid division by zero
    	if (!head) {
    		return NULL;
    	}

    	// get length and rotate count
    	int len = 0;
    	ListNode *curr = head;
    	while (curr) {
    		len++;
    		curr = curr->next;
    	}

    	k = k % len;
    	if (!k) {
    		return head;
    	}

    	// find head node of roration
        curr = head;
        for (int i = 1; i < len-k; i++) {
        	curr = curr->next;
        }

        // rotate
        ListNode *new_head = curr->next;
        curr->next = NULL;
        curr = new_head;
        while (curr->next) {
        	curr = curr->next;
        }

        curr->next = head;

        return new_head;
    }
};

int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.rotateRight(head, 6);
	displayList(head);
	
	return 0;
}