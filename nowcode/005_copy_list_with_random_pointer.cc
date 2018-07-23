#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (!head) {
    		return NULL;
    	}

    	RandomListNode* curr = head, *copy;
    	while (curr) {
    		copy = new RandomListNode(curr->label);
    		copy->next = curr->next;
    		curr->next = copy;
    		curr = copy->next;
    	}


    	curr = head, copy = head->next;
    	while (curr && copy) {
			copy->random = curr->random ? curr->random->next : NULL;
			curr = copy->next;
			copy = curr ? curr->next : NULL;
    	}

    	RandomListNode *head_copy = head->next;
    	curr = head, copy = head->next;
    	while (curr && copy) {
    		curr->next = copy->next;
    		curr = curr->next;
    		copy->next = curr ? curr->next : NULL;
    		copy = copy->next;
    	}

    	return head_copy;
    }
};

int main() {
	Solution s;
	RandomListNode *head = new RandomListNode(-1);
	s.copyRandomList(head);

	return 0;
}