#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	if (!head) {
    		return NULL;
    	}

    	// count nodes first
        ListNode *curr = head;
        int n = 1;
        while (curr->next) {
        	n++;
        	curr = curr->next;
        }
        ListNode *tail = curr;

        return mergesort(head, tail, n);
    }


    ListNode *mergesort(ListNode *head, ListNode *tail, int n) {
    	int a;

    	if (head == tail) {
    		return head;
    	}

    	// find mid and mid->next, and partition the list into two parts
    	ListNode *mid = head;
    	for (int i = 1; i < n/2; i++) {
        	mid = mid->next;
        }
        ListNode *mid_next = mid->next;		// merge proc will change ptrs, so store the node first.

    	ListNode *head1 = mergesort(head, mid, n/2);
        ListNode *head2 = mergesort(mid_next, tail, n - n/2);
        ListNode *sortedHead = merge(head1, head2, n/2, n - n/2);

        return sortedHead;
    }


    ListNode *merge(ListNode *head1, ListNode *head2, int n1, int n2) {
    	ListNode *dummy = new ListNode(-1);
    	ListNode *curr = dummy;

    	// unlike pure merge, sub lists might have not null next pointers outside target range
    	// so, shouldn't be head1 != NULL & head2 != NULL, but count the nodes
    	int cnt1 = 0, cnt2 = 0;

    	while (cnt1 < n1 && cnt2 < n2) {
    		if (head1->val < head2->val) {
    			curr->next = head1;
    			head1 = head1->next;
    			cnt1++;
    		}
    		else {
    			curr->next = head2;
    			head2 = head2->next;
    			cnt2++;
    		}
    		curr = curr->next;
    	}

    	// the sorted sub list should be followed with rest nodes outside the length of current sub list
    	while (cnt2 < n2) {
    		curr->next = head2;
    		head2 = head2->next;
    		curr = curr->next;
    		cnt2++;
    	}
    	while (cnt1 < n1) {
    		curr->next = head1;
    		head1 = head1->next;
    		curr = curr->next;
    		cnt1++;
    	}
    	curr->next = head2;

    	curr = dummy->next;
    	delete dummy;


    	return curr;
    }
};


int main() {
	int arr[] = {5,5,1,7,3,4,2,8,6};
	int n = sizeof(arr) / sizeof(int);
	ListNode *dummy = new ListNode(-1);
	ListNode *curr = dummy;
	for (int i = 0; i < n; i++) {
		curr->next = new ListNode(arr[i]);
		curr = curr->next;
	}
	ListNode *head = dummy->next;
	delete dummy;

	Solution s = Solution();
	ListNode *sortedHead = s.sortList(head);

	curr = sortedHead;
	while (curr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;

	return 0;
}