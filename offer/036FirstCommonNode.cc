/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* FindFirstCommonNode2(ListNode *head1, ListNode *head2) {
		stack<ListNode*> node1, node2;
		traverse(head1, node1);
		traverse(head2, node2);

		ListNode *prev = NULL;

		while (!node1.empty() && !node2.empty()) {
			ListNode *curr1 = node1.top();
			ListNode *curr2 = node2.top();
			node1.pop();
			node2.pop();

			if (curr1 != curr2) {
				break;
			}

			prev = curr1;
		}

		return prev;
	}

	void traverse(ListNode *head, stack<ListNode*> &nodes) {
		ListNode *curr = head;
		while (curr) {
			nodes.push(curr);
			curr = curr->next;
		}
	}

    ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
    	int len1 = getLen(head1);
    	int len2 = getLen(head2);
    	ListNode *curr1 = head1, *curr2 = head2;

    	if (len2 < len1) {
    		swap(len1, len2);
    		swap(curr1, curr2);
    	}

    	for (int i = 0; i < len2 - len1; i++) {
    		curr2 = curr2->next;
    	}

    	while (curr1 && curr2 && curr1 != curr2) {
    		curr1 = curr1->next;
    		curr2 = curr2->next;
    	}

    	return curr1;
    }

    int getLen(ListNode *head) {
    	ListNode *curr = head;
    	int cnt = 0;
    	while (curr) {
    		curr = curr->next;
    		cnt++;
    	}
    	return cnt;
    }
};