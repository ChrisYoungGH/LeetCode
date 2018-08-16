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
    ListNode *swapPairs(ListNode *head) {
    	if (!head || !head->next) {
    		return head;
    	}

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *first = head, *second = first->next;
        ListNode *prev = dummy;
        while (first && second) {
        	prev->next = second;
        	first->next = second->next;
        	second->next = first;

        	prev = first;
        	first = prev->next;
        	second = first ? first->next : NULL;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};


int main() {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.swapPairs(head);
	displayList(head);

	return 0;
}