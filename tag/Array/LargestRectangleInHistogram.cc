#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	stack<int> s;

	int n = heights.size();
	int i = 0;
	int sum = 0;
	while (i < n + 1) {
		int val = i < n ? heights[i] : 0;
		if (s.empty() || val > heights[s.top()]) {
			s.push(i);
			i++;
		}
		else {
			int t = s.top();
			s.pop();
			sum = max(sum, heights[t] * (s.empty() ? i : i - s.top() - 1));
		}
	}

	return sum;
}

int main() {
	int num[] = {2,1,5,5,6,2,3};
	int n = sizeof(num) / sizeof(int);
	vector<int> heights(num, num + n);
	cout << largestRectangleArea(heights) << endl;
	return 0;
}