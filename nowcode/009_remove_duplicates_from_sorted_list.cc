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
    	ListNode *curr = head;
    	while (curr) {
    		ListNode *curr2 = curr->next;
    		while (curr2 && curr2->val == curr->val) {
    			curr2 = curr2->next;
    		}
    		curr->next = curr2;
    		curr = curr->next;
    	}
        
        return head;
    }
};

int main() {
	int arr[] = {1,1,2,3,3};
	int n = sizeof(arr) / sizeof(int);

	ListNode *head = createList(arr, n);
	displayList(head);

	Solution s = Solution();
	s.deleteDuplicates(head);
	displayList(head);

	return 0;
}