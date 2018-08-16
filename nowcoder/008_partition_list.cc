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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallHead = new ListNode(-1);
        ListNode *largeHead = new ListNode(-1);

        ListNode *curr = head, *smallCurr = smallHead, *largeCurr = largeHead;
        while (curr) {
        	if (curr->val < x) {
        		smallCurr->next = curr;
        		smallCurr = smallCurr->next;
        	}
        	else {
        		largeCurr->next = curr;
        		largeCurr = largeCurr->next;
        	}
        	curr = curr->next;
        }
        largeCurr->next = NULL;

        smallCurr->next = largeHead->next;
        head = smallHead->next;

        delete smallHead;
        delete largeHead;

        return head;
    }
};


int main() {
	int arr[] = {1,3,2};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.partition(head, 3);

	displayList(head);

	return 0;
}