class Solution {
public:
    void push(int node) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        stack1.push(node);
    }
    
    
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int node = -1;
        if (!stack2.empty()) {
            node = stack2.top();
            stack2.pop();
        }
        
        return node;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};