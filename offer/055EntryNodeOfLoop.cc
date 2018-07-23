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
    ListNode* EntryNodeOfLoop(ListNode* head) {
    	if (!head) {
    		return NULL;
    	}

    	ListNode *fast = head, *slow = head;
    	while (fast && fast->next) {
    		fast = fast->next->next;
    		slow = slow->next;
			
			if (fast == slow) {
				break;
			}
    	}

    	if (!fast || !fast->next) {
    		return NULL;
    	}

    	fast = head;
    	while (fast != slow) {
    		fast = fast->next;
    		slow = slow->next;
    	}

    	return fast;
    }
};