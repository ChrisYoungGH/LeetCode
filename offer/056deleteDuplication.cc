#include "listUtils.h"
#include "utils.h"

#include <iostream>

using namespace std;

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
    	if (!head) {
    		return NULL;
    	}

    	ListNode *dummy = new ListNode(-1);
        dummy->next = head;
    	ListNode *prev = dummy, *curr = head;

    	while (curr) {
            int val = curr->val;
            ListNode *dup = curr->next;
            while (dup && dup->val == val) {
                dup = dup->next;
            }
            if (dup == curr->next) {
                prev = prev->next;
            }
            else {
                prev->next = dup;
            }
            curr = prev->next;
    	}

    	head = dummy->next;

    	delete dummy;

    	return head;
    }
};

int main() {
	int arr[] = {1,2,3,3,4,4,5,6,6,7};
	int n = sizeof(arr) / sizeof(int);
	ListNode *head = createList(arr, n);
    Solution s = Solution();
    ListNode *head2 = s.deleteDuplication(head);
	displayList(head2);

	return 0;
}