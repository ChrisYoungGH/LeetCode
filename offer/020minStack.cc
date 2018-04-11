class Solution {
public:
	void push(int val) {
		mainStack.push(val);

		if (minStack.empty()) {
			minStack.push(val);
		}
		else {
			minStack.push(std::min(val, minStack.top()));
		}
	}

	void pop() {
		if (!mainStack.empty()) {
			mainStack.pop();
		}
		if (!minStack.empty()) {
			minStack.pop();
		}
	}

	int top() {
		if (!mainStack.empty()) {
			return mainStack.top();
		}
		return -1;
	}

	int min() {
		if (!minStack.empty()) {
			return minStack.top();
		}
		return INT_MAX;
	}

private:
	stack<int> mainStack;
	stack<int> minStack;
};