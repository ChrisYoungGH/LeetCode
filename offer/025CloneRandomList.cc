#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
	// use hash map
	RandomListNode *Clone1(RandomListNode *head) {
		if (!head) {
			return NULL;
		}

		RandomListNode *headCopy = new RandomListNode(head->label);
		RandomListNode *curr = head->next, *currCopy = headCopy;

		map<RandomListNode*, RandomListNode*> randomMap;
		randomMap[head] = headCopy;


		while (curr) {
			currCopy->next = new RandomListNode(curr->label);
			currCopy = currCopy->next;
			randomMap[curr] = currCopy;
			curr = curr->next;
		}

		curr = head;
		while (curr) {
			randomMap[curr]->random = randomMap[curr->random];
			curr = curr->next;
		}

		return headCopy;
	}


	// no extra space
	RandomListNode *Clone2(RandomListNode *head) {
		if (!head) {
			return NULL;
		}

		// copy node and put behind original node
		RandomListNode *curr = head;
		while (curr) {
			RandomListNode *copy = new RandomListNode(curr->label);
			copy->next = curr->next;
			curr->next = copy;
			curr = copy->next;
		}

		// set random ptrs
		RandomListNode *headCopy = head->next;
		RandomListNode *currCopy = headCopy;
		curr = head;
		while (curr) {
			currCopy->random = curr->random ? curr->random->next : NULL;
			curr = currCopy->next;
			currCopy = curr ? curr->next : NULL;
		}

		// partition original list and clone list
		curr = head, currCopy = head->next;
		while (curr) {
			curr->next = currCopy->next;
			curr = curr->next;
			currCopy->next = curr ? curr->next : NULL;
			currCopy = currCopy->next;
		}

		return headCopy;
	}
};

void display(RandomListNode *curr) {
	while (curr) {
		cout << curr->label << " " << (curr->next ? curr->next->label : -1) << " " << (curr->random ? curr->random->label : -1) << "; ";
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	Solution s = Solution();
	RandomListNode **nodes = new RandomListNode*[5];
	for (int i = 4; i >= 0; i--) {
		nodes[i] = new RandomListNode(i+1);
		nodes[i]->next = i+1 < 5 ? nodes[i+1] : NULL;
	}
	nodes[0]->random = nodes[2];
	nodes[1]->random = nodes[4];
	nodes[3]->random = nodes[1];

	RandomListNode *head = nodes[0];
	RandomListNode *copy1 = s.Clone1(head);
	RandomListNode *copy2 = s.Clone2(head);

	display(head);
	display(copy1);
	display(copy2);

	return 0;
}