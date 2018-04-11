#include<stack>

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        stack<int> nodeVal;
        ListNode *curr = head;
        
        while (curr) {
            nodeVal.push(curr->val);
            curr = curr->next;
        }
        
        while (!nodeVal.empty()) {
            res.push_back(nodeVal.top());
            nodeVal.pop();
        }
        
        return res;
    }
};