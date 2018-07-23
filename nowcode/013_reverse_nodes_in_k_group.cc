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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if (!head) {
    		return NULL;
    	}

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *frontTail = dummy;
        ListNode *currHead = head, *currTail = head;
        ListNode *backHead = NULL;

        while (1) {
	        ListNode *curr = currHead;
	        for (int i = 0; i < k-1; i++) {
	        	curr = curr->next;
	        	if (!curr) {
	        		break;
	        	}
	        }
	        if (!curr) {
	        	break;
	        }
	        currTail = curr;
	        backHead = currTail->next;

	        reverse(frontTail, currHead, currTail, backHead);

	        if (!backHead) {
	        	break;
	        }
	        
	        frontTail = currHead;
	        currHead = backHead;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }

    void reverse(ListNode *frontTail, ListNode *head, ListNode *tail, ListNode *backHead) {
    	if (!head || !tail || head == tail) {
    		return;
    	}

    	ListNode *prev = frontTail, *curr = head, *next = curr->next;
    	while (curr != backHead) {
    		curr->next = prev;
    		prev = curr;
    		curr = next;
    		next = next ? next->next : NULL;
    	}

    	frontTail->next = tail;
    	head->next = backHead;
    }
};

int main() {
	int arr[] = {1,2};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.reverseKGroup(head, 2);
	displayList(head);

	return 0;
}