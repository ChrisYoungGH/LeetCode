#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
	    int m = matrix.size();
	    if (m == 0) {
	    	return 0;
	    }
	    int n = matrix[0].size();

	    vector<int> sum(n, 0);
	    int maxMatrixArea = 0;

	    for (int i = 0; i < m; i++) {
	    	getHistgram(sum, matrix[i], n);

	    	maxMatrixArea = max(maxMatrixArea, getMaxHistgramArea(sum, n));
	    }

		return maxMatrixArea;	    
	}

	void getHistgram(vector<int> &sum, vector<char> &row, const int n) {
		for (int i = 0; i < n; i++) {
			int val = row[i] - '0';
			sum[i] = val == 0 ? 0 : (sum[i] + val);
		}
	}

	int getMaxHistgramArea(vector<int> &height, const int n) {
		stack<int> s;

		int i = 0;
		int maxArea = 0;
		while (i < n + 1) {
			int val = i < n ? height[i] : 0;
			if (s.empty() || val > height[s.top()]) {
				s.push(i);
				i++;
			}
			else {
				int t = s.top();
				s.pop();
				maxArea = max(maxArea, height[t] * (s.empty() ? i : (i - s.top() - 1)));
			}
		}

		return maxArea;
	}
};

int main() {
	Solution s = Solution();
	vector<vector<char> > matrix = {{'1','0','1','0','0'},
									{'1','0','1','1','1'},
									{'1','1','1','1','1'},
									{'1','0','0','1','0'}};
	cout << s.maximalRectangle(matrix) << endl;
	return 0;
}