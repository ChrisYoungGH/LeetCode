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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if (!head) {
    		return head;
    	}

    	ListNode *targetHead = head, *targetTail = head;
    	ListNode *frontTail = head, *backHead = NULL;

    	// get position of target list and its boundaries
    	int mc = m;
    	mc--; n--;
    	while (n) {
    		if (mc > 1) {
    			frontTail = frontTail->next;
    			mc--;
    		}
    		targetTail = targetTail->next;
    		n--;
    	}
    	targetHead = frontTail->next;

    	if (m == 1) {
    		frontTail = NULL;
    		targetHead = head;
    	}

    	backHead = targetTail->next;

    	// reverse sub list
    	ListNode *prev = NULL, *curr = targetHead, *next = curr->next;
    	while (curr != backHead) {
    		curr->next = prev;
    		prev = curr;
    		curr = next;
    		next = next ? next->next : NULL;
    	}

    	if (frontTail) {
    		frontTail->next = targetTail;
    	}
    	else {
    		head = targetTail;
    	}
    	targetHead->next = backHead;


    	return head;
    }
};

int main() {
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr) / sizeof(int);
	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.reverseBetween(head, 1, 6);
	displayList(head);

	return 0;
}