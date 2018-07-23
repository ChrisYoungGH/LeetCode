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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
        	int v1 = 0, v2 = 0;
        	if (l1) {
        		v1 = l1->val;
        		l1 = l1->next;
        	}
        	if (l2) {
        		v2 = l2->val;
        		l2 = l2->next;
        	}

        	int sum = v1 + v2 + carry;
        	carry = sum / 10;

        	curr->next = new ListNode(0);
        	curr = curr->next;
        	curr->val = sum % 10;
        }

        ListNode *head = dummy->next;
        delete dummy;

        return head;
    }
};

class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *curr1 = l1, *curr2 = l2, *prev1 = NULL;
        int up = 0;
        while (curr1 && curr2) {
        	curr1->val += curr2->val + up;
        	up = curr1->val / 10;
        	curr1->val %= 10;

        	prev1 = curr1;
        	curr1 = curr1->next;
        	curr2 = curr2->next;
        }

        if (!curr1) {
        	curr1 = curr2;
        	if (prev1) {
        		prev1->next = curr1;
        	}
        	else {
        		l1 = curr1;
        	}
        }

        while (curr1) {
        	curr1->val += up;
        	up = curr1->val / 10;
        	curr1->val %= 10;

        	prev1 = curr1;
        	curr1 = curr1->next;
        }
        if (up) {
        	prev1->next = new ListNode(up);
        }

        return l1;
    }
};


int main() {
	int arr1[] = {};
	int arr2[] = {1, 4};

	int n1 = sizeof(arr1) / sizeof(int);
	int n2 = sizeof(arr2) / sizeof(int);

	ListNode *l1 = createList(arr1, n1);
	ListNode *l2 = createList(arr2, n2);

	Solution2 s = Solution2();
	ListNode *sum = s.addTwoNumbers(l1, l2);
	displayList(sum);

	return 0;
}