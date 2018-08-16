#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) {
        	return 0;
        }

        int curr_min = prices[0], curr_max = prices[0];
        int global_max = 0;
        for (int i = 1; i < n; i++) {
        	if (prices[i] < curr_min) {
        		curr_min = curr_max = prices[i];
        	}
        	else if (prices[i] > curr_max) {
        		curr_max = prices[i];
        		global_max = max(curr_max - curr_min, global_max);
        	}
        }

        return global_max;
    }
};

int main() {
	vector<int> vec = {7,6,4,3,1,8,7};
	Solution s = Solution();
	cout << s.maxProfit(vec) << endl;
	return 0;
}