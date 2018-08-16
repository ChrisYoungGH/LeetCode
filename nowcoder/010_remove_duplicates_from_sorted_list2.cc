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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *curr = head, *prev = dummy;
        while (curr) {
        	ListNode *curr2 = curr->next;
        	while (curr2 && curr2->val == curr->val) {
        		curr2 = curr2->next;
        	}
        	if (curr2 == curr->next) {
        		prev = curr;
        	}
        	prev->next = curr2;
        	curr = curr2;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};

int main() {
	int arr[] = {1,1,2,3,3,4,4,5};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	head = s.deleteDuplicates(head);
	displayList(head);

	return 0;
}